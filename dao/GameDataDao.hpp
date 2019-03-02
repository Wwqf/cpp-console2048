#ifndef GAME_DATA_DAO_HPP
#define GAME_DATA_DAO_HPP

    #include "GameData.hpp"
    #include <fstream>
    class GameDataDao {
        public:
            bool write_sc(GameDataSc sc);
            bool write_ches(GameDataChessBoard ches);
            bool write_gamepro(GameDataGameProgress gdp);

            GameDataSc read_sc();
            GameDataChessBoard read_ches();
            GameDataGameProgress read_gameProgress();
    };

#endif