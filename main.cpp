#include "main.hpp"
#include "utils/Random.hpp"
#include "dao/GameDataDao.hpp"
#include "game/GameView.hpp"
// 怎让让局部对象持久存在?
GameScreenData& gameInit() {
    
    int sh = Utils::getScreenSize().first;
    int sw = Utils::getScreenSize().second;
    if (sh < 22 || sw < 51) {
        cout << "this window is too small." << endl;
        exit(0);
    }

    Point tscPos, cscPos, tipPos;
    ScoreFonts sf(tscPos, cscPos);
    TipFonts tf(tipPos);

    ChessBoard ches(sh, sw);
    Chess cess(sh, sw, ches);

    static GameScreenData gsd(sh, sw, sf, tf, ches, cess);
    return gsd;
}

int main() {
    WINDOW *scr = GameView::open_curses();
    GameView gm(scr, gameInit());
    gm.draw();
    gm.monitorKeyBoardEvent(); 
    // int c ;
    // move(1, 1); 
    // int ct = 1;
    // while ( (c = getch()) ) {
    //     c = getch(); c = getch();
    //     if (c == 'A') cout << "a";
    //     else if (c == 'B') cout << "b";
    //     else if (c == 'C') cout << "c";
    //     else if (c == 'D') cout << "d";
    //     cout << '[' << c << ']';
    //     break;
    // }
    // GameView::close_curses();
    return 0;
}

void generator_write_chesAndSc() {
    array arr;
    std::vector<int> item;
    randomCls r;
    for (int i = 0; i < ches_len; i++) {
        std::vector<int> item;
        for (int j = 0; j < ches_len; j++) {
            item.push_back(r.randomInt(0, 30));
        } arr.push_back(item);
    }

    GameDataDao gdd;
    GameDataSc gds(10, 10);
    GameDataChessBoard gdc(arr);


    cout << (gdd.write_sc(gds) ? "success" : "failed") << endl;
    cout << (gdd.write_ches(arr) ? "success" : "failed");
}

void generator_read_ches_sc() {
    GameDataDao gdd;
    GameDataChessBoard gdc = gdd.read_ches();
    GameDataSc gds = gdd.read_sc();

    cout << gds.total_sc << ' ' << gds.current_sc << endl;

    for (int i = 0; i < ches_len; i++) {
        for (int j = 0; j < ches_len; j++) {
            cout << gdc.chessboard[i][j] << " ";
        } cout << endl;
    }
}