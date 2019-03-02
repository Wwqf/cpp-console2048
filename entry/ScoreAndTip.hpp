#ifndef SCORE_TIP_HPP
#define SCORE_TIP_HPP

    #include "../main.hpp"

    class ScoreFonts {
        public: 
            Point tsc_pos, csc_pos;
            const string tsc_str, csc_str;
            const int tsc_str_width = 16, csc_str_width = 16;
            ScoreFonts(Point tsc_p, Point csc_p): tsc_pos(tsc_p), csc_pos(csc_p), 
                tsc_str("Highest score : "), csc_str("Current score : ") { }

            void draw(int tsc, int csc); // 最高分, 当前得分

            void setTsc(Point &pos); // 文字坐标
            void setCsc(Point &pos);
    };

    class TipFonts {
        public: 
            Point pos;
            const string tip;
            TipFonts(Point _pos): pos(_pos), 
                tip("Please use up down left right key move.") { }

            void set(Point &_pos);
            void draw(); // 绘制
    };

#endif