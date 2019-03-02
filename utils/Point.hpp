#ifndef POINT_HPP
#define POINT_HPP

    class Point {
        public: 
            int x, y;
            
            Point() = default;
            Point(int sy, int sx): y(sy), x(sx) { }
            
            void set(int sy, int sx);
            void set(const Point &other);
    };

#endif