#include "ScoreAndTip.hpp"

void ScoreFonts::draw(int tsc, int csc) {
    std::ostringstream oss; 
    oss.str(""); oss.clear();
    oss << tsc_str << tsc;
    mvaddstr(tsc_pos.y, tsc_pos.x, "                      ");
    mvaddstr(tsc_pos.y, tsc_pos.x, oss.str().c_str());
    oss.str(""); oss.clear();
    oss << csc_str << csc;
    mvaddstr(csc_pos.y, csc_pos.x, "                      ");
    mvaddstr(csc_pos.y, csc_pos.x, oss.str().c_str());
}

void TipFonts::draw() {
    mvaddstr(pos.y, pos.x, tip.c_str());
}


void ScoreFonts::setTsc(Point &pos) {
    tsc_pos.set(pos);
}
void ScoreFonts::setCsc(Point &pos) {
    csc_pos.set(pos);
}

void TipFonts::set(Point &_pos) {
    pos.set(_pos);
}