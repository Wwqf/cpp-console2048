#ifndef MAIN_HPP
#define MAIN_HPP

    #define sc_direc "/home/yanuas/project/sc_direc.sc" // 分数路径
    #define ches_direc "/home/yanuas/project/ches_direc.ches" // 棋盘数据路径
    #define game_direc "/home/yanuas/project/game.gm" // 游戏进度路径

    #include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;

    #include <vector>
    typedef std::vector<std::vector<int>> array; // 棋盘
    const int ches_len = 4; // 棋盘长度

    #include <ncursesw/curses.h> // 宽字符curses库

    #include <string>
    #include <sstream>
    using std::string;

    #include "utils/Point.hpp"
    #include <cstdio>
    #include <cstring>
    #include <cstdlib>

    #include <wchar.h> // wstring

    // 检测终端的大小
    #include <linux/input.h>
    #include <unistd.h>

    const int box_size = 2;
    const int font_size = 3;

    #include <locale>
    #include <unistd.h>
#endif