#include  "Chessboard.hpp"

void ChessBoard::init_chessboard() {

    startPos.set(
        (sh - box_size - height) / 2,
        (sw - box_size - width) / 2
    ); 

    // table[0][0] ~ table[0][48] 为顶部显示字符
    // table[1][0] ~ table[3][48] 为一行格显示字符

    int speics_idx[] = {12, 24, 36, 48}; // 特殊下标字符

    // 初始化顶部字符
    for (int i = 0; i < width; i++) {
        if (i == 0) table[0][i] = Utils::stringTowstring(left_up);
        else if (i == speics_idx[0] || i == speics_idx[1] || 
                i == speics_idx[2] || i == speics_idx[3]) table[0][i] = Utils::stringTowstring(right_up);
        else table[0][i] = Utils::stringTowstring(hor_line); 
    }

        // 初始化行格字符
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 1 || i == 2 || i == 3) {
                if (j == 0 || j == speics_idx[0] || j == speics_idx[1] || 
                j == speics_idx[2] || j == speics_idx[3]) table[i][j] = Utils::stringTowstring(ver_line);
                else table[i][j] = Utils::stringTowstring(none);
            } else {
                if (j == 0) table[i][j] = Utils::stringTowstring(left_down);
                else if (j == speics_idx[0] || j == speics_idx[1] || 
                j == speics_idx[2] || j == speics_idx[3]) table[i][j] = Utils::stringTowstring(right_down);
                else table[i][j] = Utils::stringTowstring(hor_line);
            }
        }
    }
}

void ChessBoard::draw() {
    for (int i = 0; i < width; i++) {
        mvaddwstr(startPos.y, 
                    startPos.x + i, 
                    table[0][i].c_str());
    }

    for (int count = 0; count < 4; count++) {
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < width; j++) {
                mvaddwstr(startPos.y + (count * 4) + i, 
                    startPos.x + j, 
                    table[i][j].c_str());
            }
        }
    } 
}