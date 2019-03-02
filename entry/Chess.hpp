#ifndef CHESS_HPP
#define CHESS_HPP

    #include "../main.hpp"
    #include "../utils/Utils.hpp"
    #include "Chessboard.hpp"

    class Chess {
        public: 
            int value[4][4];
            Point value_pos[4][4];

            int sh, sw;
            ChessBoard ches;

            Chess(int msh, int msw, ChessBoard mches): sh(msh), sw(msw), ches(mches) {
                init_chess();
            }
            void draw(); // 绘制

            void conversionToValue(array data); // 将array转换为int
            array conversionToArray(); // 将value转换为array
            void clearValue();

            void move_up(int &sc); // 按↑
            void move_down(int &sc); // 按↓
            void move_left(int &sc); // 按←
            void move_right(int &sc); // 按→
        private: 
            void init_chess(); // 属性初始化
    };

#endif