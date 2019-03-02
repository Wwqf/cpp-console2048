#ifndef UTILS_HPP
#define UTILS_HPP
    #include "../main.hpp"

    class Utils {
        public: 
            static std::wstring stringTowstring(const string &str);
            static int numberLength(int num);
            static std::pair<int, int> getScreenSize();
        private: 
    };

#endif