#include "GameDataDao.hpp"

bool GameDataDao::write_sc(GameDataSc sc) {
    std::ofstream out(sc_direc, std::ios::out);
    if (!out.is_open()) return false;
    out << sc.total_sc << ' ' << sc.current_sc;
    out.close();
    return true;
}
bool GameDataDao::write_ches(GameDataChessBoard ches) {
    std::ofstream out(ches_direc, std::ios::out);
    if (!out.is_open()) return false;
    for (int i = 0; i < ches_len; i++) {
        for (int j = 0; j < ches_len; j++) {
            out << ches.chessboard[i][j] << ' ';
        } out << '\n';
    }
    out.close();
    return true;
}
bool GameDataDao::write_gamepro(GameDataGameProgress gdp)  {
    std::ofstream out(game_direc, std::ios::out);
    if (!out.is_open()) return false;
    out << gdp.has;
    out.close();
    return true;
}

GameDataSc GameDataDao::read_sc() {
    GameDataSc gds;
    std::ifstream in(sc_direc, std::ios::in);
    if (in.is_open()) {
        in >> gds.total_sc >> gds.current_sc;
        in.close();
    }
    return gds;
}
GameDataChessBoard GameDataDao::read_ches() {
    GameDataChessBoard gdc;
    std::ifstream in(ches_direc, std::ios::in);
    int dt;
    if (in.is_open()) {
        for (int i = 0; i < ches_len; i++) {
            std::vector<int> item;
            item.clear();
            for (int j = 0; j < ches_len; j++) {
                in >> dt;
                item.push_back(dt);
            } gdc.chessboard.push_back(item);
        }
        in.close();
    }
    return gdc;
}
GameDataGameProgress GameDataDao::read_gameProgress() {
    GameDataGameProgress gdp;
    std::ifstream in(game_direc, std::ios::in);
    if (in.is_open()) {
        in >> gdp.has;
        in.close();
    }
    return gdp;
}