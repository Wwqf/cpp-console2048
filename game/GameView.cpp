#include "GameView.hpp"

WINDOW* GameView::open_curses() {
    WINDOW *scr = initscr(); // 启动curses
    noecho(); // 禁止显示字符
    setlocale(LC_ALL, ""); // 设置编码为默认模式
    box(scr, ACS_VLINE, ACS_HLINE); // 绘制边框
    return scr;
}
void GameView::close_curses() {
    endwin(); // 关闭curses
}
void GameView::draw() {
    gsd.tf.draw();
    gsd.sf.draw(gsd.tsc, gsd.csc);
    gsd.ches.draw();
    gsd.cess.draw();
    refresh(); // 刷新
}

void GameScreenData::gameValueInit() {
    tsc = csc = 0;
    Point tfp(1, 1);
    Point tscp(
        ches.startPos.y - 3,
        (sw - box_size - sf.tsc_str_width - Utils::numberLength(tsc)) / 2
    );
    Point cscp(
        tscp.y + 1,
        (sw - box_size - sf.csc_str_width - Utils::numberLength(csc)) / 2
    );
    sf.setTsc(tscp);
    sf.setCsc(cscp);
    tf.set(tfp);
    gen_two_prob = 0.5;
    gameState = GAME_START;
}

void GameView::monitorKeyBoardEvent() {
    if (gsd.gameState == GAME_START) { // 游戏开始
        // 游戏开始询问是否读取上次游戏进度(如果有)
        GameDataDao gdd;
        gsd.tsc = gdd.read_sc().total_sc;
        if (gdd.read_gameProgress().has) { // 有进度
            gsd.csc = gdd.read_sc().current_sc;
            gsd.cess.conversionToValue(gdd.read_ches().chessboard);
        }
        gsd.gameState = GAME_RUN;
        draw();
        monitorKeyBoardEvent();
    } else if (gsd.gameState == GAME_RUN) { // 游戏运行
        Event et = running();
        if (et == KEY_EVENT_ESC) { // 按下esc键
            gsd.gameState = GAME_PAUSE;
        } else if (et == NO_SPACE) {
            gsd.gameState = GAME_OVER;
        }
        monitorKeyBoardEvent();
    } else if (gsd.gameState == GAME_PAUSE) { // 游戏暂停
        Event et = gamePause();
        if (et == CHOICE_EXIT) {
            mvaddstr(gsd.sh - 2, 1, "                                               ");
            if (isSaveDataTag()) saveData(true);
            else saveData(false);
            close_curses();
            exit(0);
        } else if (et == CHIOCE_START_OVER) {
            gsd.tsc = 0;
            gsd.csc = 0;
            gsd.cess.clearValue();

            gsd.gameState = GAME_START;
            mvaddstr(gsd.sh - 2, 1, "                                               ");
            monitorKeyBoardEvent();
        } else {
            gsd.gameState = GAME_START;
            mvaddstr(gsd.sh - 2, 1, "                                               ");
            monitorKeyBoardEvent();
        }

    } else if (gsd.gameState == GAME_OVER) { // 游戏结束
        saveData(false);
        if (gameOver() == CHOICE_EXIT) {
            close_curses();
            exit(0);
        } else {
            gsd.tsc = 0;
            gsd.csc = 0;
            gsd.cess.clearValue();

            gsd.gameState = GAME_START;
            mvaddstr(gsd.sh - 2, 1, "                                               ");
            monitorKeyBoardEvent();
        }
    } 
}
Event GameView::running() {
    char c; 
    while ( (c = getch()) ) {
        // 移植性有问题, 可能出现bug
        c = getch(); c = getch();
        if (c == INPUT_UP) { 
            gsd.cess.move_up(gsd.csc);
            if (generate_chess() == NO_SPACE) return NO_SPACE;
        } else if (c == INPUT_DOWN) {
            gsd.cess.move_down(gsd.csc);
            if (generate_chess() == NO_SPACE) return NO_SPACE;
        } else if (c == INPUT_LEFT) {
            gsd.cess.move_left(gsd.csc);
            if (generate_chess() == NO_SPACE) return NO_SPACE;
        } else if (c == INPUT_RIGHT) {
            gsd.cess.move_right(gsd.csc);
            if (generate_chess() == NO_SPACE) return NO_SPACE;
        } else if (c == INPUT_ESC) return KEY_EVENT_ESC;
        draw();
    }
    return NONE_EVENT;
}

Event GameView::generate_chess() {
    if (isGameOver() == NO_SPACE) {
        return NO_SPACE;
    }
    int y, x;
    while (true) {
        y = rcls.randomInt(0, 4);
        x = rcls.randomInt(0, 4);
        if (gsd.cess.value[y][x] == 0) {
            gsd.cess.value[y][x] = rcls.randomZeroOneDistribution();
            break;
        }
    }
    return NONE_EVENT;
}
Event GameView::isGameOver() {
    int space_cal = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (gsd.cess.value[i][j] != 0) space_cal++;
        }
    }
    return space_cal == 16 ? NO_SPACE : NONE_EVENT;
}

Event GameView::gamePause() {
    mvaddstr(gsd.sh - 2, 1, "Do you want to start over(y/n, q by quit): ");
    int c = getch();
    if (c == 'y' || c == 'Y') return CHIOCE_START_OVER;
    else if (c == 'n' || c == 'N') return CHIOCE_NONE;
    else if (c == 'q' || c == 'Q') return CHOICE_EXIT;
    else return gamePause();
}
Event GameView::gameOver() {
    mvaddstr(gsd.sh - 2, 1, "game over, want to play game again? (y/n): ");
    int c = getch();
    if (c == 'y' || c == 'Y') return CHOICE_EXIT;
    else if (c == 'n' || c == 'N') return CHIOCE_NONE;
    else return gameOver();
}

void GameView::saveData(bool has) {
    GameDataDao gdd;
    if (gsd.csc > gsd.tsc) gsd.tsc = gsd.csc;
    GameDataSc gs(gsd.tsc, gsd.csc);
    gdd.write_sc(gs);

    GameDataChessBoard gcb(gsd.cess.conversionToArray());
    gdd.write_ches(gcb);

    GameDataGameProgress gdp(has);
    gdd.write_gamepro(gdp);
}

bool GameView::isSaveDataTag() {
    mvaddstr(gsd.sh - 2, 1, "whether to stroage game data(y/n): ");
    int c = getch();
    if (c == 'y' || c == 'Y') return true;
    else if (c == 'n' || c == 'N') return false;
    else return isSaveDataTag();
}