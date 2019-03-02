#include "Chess.hpp"

void Chess::init_chess() {
    clearValue();
    int speics_idx[] = {12, 24, 36, 48};
    for (int i = 0; i < 4; i++) {
        int currentY = ches.startPos.y + (i * 4) + 2;
        int lef = ches.startPos.x + 1, rig = lef;
        for (int j = 0; j < 4; j++) {
            int len = Utils::numberLength(value[i][j]);
            rig += 11;
            value_pos[i][j].set(currentY, (lef + rig - len) / 2 + 1);
            lef += 12;
        }
    }
}

void Chess::draw() {
    std::stringstream ss;
    ss.str("");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ss.clear(); ss.str("");
            ss << value[i][j];
            if (value[i][j] == 0) continue;
            mvaddstr(value_pos[i][j].y, value_pos[i][j].x, 
                ss.str().c_str());
        }
    }
}

void Chess::conversionToValue(array data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            value[i][j] = data[i][j];
        }
    }
}
array Chess::conversionToArray() {
    array res;
    vector<int> item;
    for (int i = 0; i < 4; i++) {
        item.clear();
        for (int j = 0; j < 4; j++) {
            item.push_back(value[i][j]);
        } res.push_back(item);
    }
    return res;
}
void Chess::clearValue() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            value[i][j] = 0;
        }
    }
}

/*
 2048核心思想:
    假设第一行的数据为: 4 2 2 4
    1. 从末尾开始, 如果当前值与上位值一样, 则相加, 并将指针向后移动一位.
    2. 如果当前值为0, 那么将上位值赋给当前值, 然后清除
    2). 特判: 当前值是0, 上位值是0, 则指针继续向前移动.
    3. 若1, 2两项都不操作, 则指针向前移动.
*/

void Chess::move_up(int &sc) {
    // 横不变, 纵变
    for (int x = 0; x < 4; x++) {
        for (int ite = 0; ite < 3; ) {
            if (value[ite][x] == 0 || value[ite][x] == value[ite + 1][x]) {
                if (value[ite][x] == 0 && value[ite + 1][x] == 0) {
                    ite++;
                    continue;
                }
                if (value[ite][x] == value[ite + 1][x]) sc += value[ite][x];
                value[ite][x] += value[ite + 1][x];
                value[ite + 1][x] = 0;
                ite = (ite <= 0 ? 0 : --ite);
            } else {
                ite++;
            }
        }
    }
}
void Chess::move_down(int &sc) {
    // 横不变, 纵变
    for (int x = 0; x < 4; x++) {
        for (int ite = 3; ite > 0; ) {
            if (value[ite][x] == 0 || value[ite][x] == value[ite - 1][x]) {
                if (value[ite][x] == 0 && value[ite - 1][x] == 0) {
                    ite--;
                    continue;
                }
                if (value[ite][x] == value[ite - 1][x]) sc += value[ite][x];
                value[ite][x] += value[ite - 1][x];
                value[ite - 1][x] = 0;
                ite = (ite >= 3 ? 3 : ++ite);
            } else {
                ite--;
            }
        }
    }
}
void Chess::move_left(int &sc) {
    // 横变, 纵不变
    for (int y = 0; y < 4; y++) {
        for (int ite = 0; ite < 3; ) {
            if (value[y][ite] == 0 || value[y][ite] == value[y][ite + 1]) {
                if (value[y][ite] == 0 && value[y][ite + 1] == 0) {
                    ite++;
                    continue;
                }
                if (value[y][ite] == value[y][ite + 1]) sc += value[y][ite];
                value[y][ite] += value[y][ite + 1];
                value[y][ite + 1] = 0;
                ite = (ite <= 0 ? 0 : --ite);
            } else {
                ite++;
            }
        }
    }
}
void Chess::move_right(int &sc) {
    // 横变, 纵不变
    int sum = 0;
    for (int y = 0; y < 4; y++) {

        for (int ite = 3; ite > 0; ) {
            if (value[y][ite] == 0 || value[y][ite] == value[y][ite - 1]) {
                if (value[y][ite] == 0 && value[y][ite - 1] == 0) {
                    ite--;
                    continue;
                }
                if (value[y][ite] == value[y][ite - 1]) sc += value[y][ite];
                value[y][ite] += value[y][ite - 1];
                value[y][ite - 1] = 0;
                ite = (ite >= 3 ? 3 : ++ite);
            } else {
                ite--;
            }
        }

    }
    sc += sum;
}