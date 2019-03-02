#ifndef GAME_DATA_HPP
#define GAME_DATA_HPP

    #include "../main.hpp"
    // 分数
    class GameDataSc {
        public:
            unsigned int total_sc;
            unsigned int current_sc;
            GameDataSc() = default;
            GameDataSc(int tsc, int csc): total_sc(tsc), current_sc(csc) { }
    };
    // 游戏数据
    class GameDataChessBoard {
        public:
            array chessboard;
            GameDataChessBoard() = default;
            GameDataChessBoard(array ches): chessboard(ches) { }
    };

    class GameDataGameProgress {
        public: 
            bool has;
            GameDataGameProgress(): has(false) { }
            GameDataGameProgress(bool _has): has(_has) { }
    };
#endif