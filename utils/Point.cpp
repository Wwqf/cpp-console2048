#include "Point.hpp"

void Point::set(int sy, int sx) {
    y = sy; x = sx;
}

void Point::set(const Point &other) {
    y = other.y;
    x = other.x;
}