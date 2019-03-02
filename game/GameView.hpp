#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

    #include "../main.hpp"
    #include "../entry/ScoreAndTip.hpp"
    #include "../entry/Chessboard.hpp"
    #include "../entry/Chess.hpp"
    #include "../utils/Utils.hpp"
    #include "../dao/GameDataDao.hpp"
    #include "../utils/Random.hpp"

    #define INPUT_UP 'A'
    #define INPUT_DOWN 'B'
    #define INPUT_RIGHT 'C'
    #define INPUT_LEFT 'D'
    #define INPUT_ESC 27

    // game state
    enum State {
        GAME_START,
        GAME_RUN,
        GAME_OVER,
        GAME_PAUSE
    };

    enum Event {
        NONE_EVENT, // 没有发生任何事情
        KEY_EVENT_ESC, // 按下esc退出
        NO_SPACE, // 没有空位生成棋子

        CHOICE_EXIT,
        CHIOCE_NONE,
        CHIOCE_START_OVER,
    };

    class GameScreenData {
        public: 
            State gameState;

            int tsc, csc; // 分值
            int sh, sw; // 屏幕宽度高度
            
            ScoreFonts sf; // 分值
            TipFonts tf;    // 提示
            ChessBoard ches; // 棋盘
            Chess cess; // 棋子

            double gen_two_prob; // 出现2的概率

            GameScreenData() = default;
            GameScreenData(int _sh, int _sw, ScoreFonts msf, TipFonts mtf, ChessBoard mches, Chess mcess): 
                    sh(_sh), sw(_sw), sf(msf), tf(mtf), ches(mches), cess(mcess) {

                gameValueInit();
            }
        private: 
            void gameValueInit(); // 游戏初始化
    };


    class GameView {
        public: 
            
            static WINDOW* open_curses();
            static void close_curses();

            GameView(WINDOW *sc, GameScreenData gs): scr(sc), gsd(gs) { }

            void draw(); // 绘制
            void monitorKeyBoardEvent(); // 键盘监听事件
            Event running(); 

        private: 
            WINDOW *scr;
            GameScreenData gsd;
            randomCls rcls;

            Event generate_chess(); // 生成棋子
            Event isGameOver(); // 游戏是否结束

            Event gamePause();
            Event gameOver(); 

            void saveData(bool has);
            bool isSaveDataTag();
    };

#endif