#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

    #include "../main.hpp"
    #include "../utils/Utils.hpp"
    // 界面字符(宽字符)
    #define left_up "┌"
    #define left_down "└"
    #define right_up "┐"
    #define right_down "┘"
    #define hor_line "─"
    #define ver_line "│"
    #define none " "

    using std::vector;
    class ChessBoard {
        public: 
            const int width = 49, height = 17;
            int sh, sw;
            std::wstring table[5][49];
            Point startPos;
            ChessBoard(int msh, int msw): sh(msh), sw(msw) {
                init_chessboard();
            }

            void draw(); // 绘制
        private: 
            void init_chessboard(); // 属性初始化
    };

#endif

/* chessboard
  0 ┌───────────┐───────────┐───────────┐───────────┐
  1 │           │           │           │           │
  2 │           │           │           │           │
  3 │           │           │           │           │
  4 └───────────┘───────────┘───────────┘───────────┘
    │           │           │           │           │
    │           │           │           │           │
    │           │           │           │           │
    └───────────┘───────────┘───────────┘───────────┘
    │           │           │           │           │
    │           │           │           │           │
    │           │           │           │           │
    └───────────┘───────────┘───────────┘───────────┘
    │           │           │           │           │
    │           │           │           │           │
    │           │           │           │           │
    └───────────┘───────────┘───────────┘───────────┘
*/