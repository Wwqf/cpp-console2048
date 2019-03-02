#include "Utils.hpp"

std::wstring Utils::stringTowstring(const string &str) {
    string str_locale = setlocale(LC_ALL, "");
    const char *cstr = str.c_str();

    size_t destSize = mbstowcs(NULL, cstr, 0) + 1;
    wchar_t* wchar_dest = new wchar_t[destSize];
    wmemset(wchar_dest, 0, destSize);
    mbstowcs(wchar_dest, cstr, destSize);

    std::wstring res = wchar_dest;
    delete[] wchar_dest;
    setlocale(LC_ALL, str_locale.c_str());
    return res;
}

int Utils::numberLength(int num) {
    int len = 0;
    while (num) {
        len++;
        num /= 10;
    }
    return len == 0 ? 1 : len;
}

std::pair<int, int> Utils::getScreenSize() {
    struct winsize size;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
    std::pair<int, int> res;
    res.first = size.ws_row; // y
    res.second = size.ws_col; // x
    return res;
}