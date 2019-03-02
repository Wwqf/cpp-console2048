main.out : main.o Random.o Point.o Utils.o GameDataDao.o ScoreAndTip.o Chess.o Chessboard.o GameView.o
	g++ main.o Random.o Point.o Utils.o GameDataDao.o ScoreAndTip.o Chess.o Chessboard.o GameView.o -lncursesw -o main.out -std=c++11
main.o : utils/Random.hpp main.hpp main.cpp
	g++ -g -c main.cpp -std=c++11
Random.o : utils/Random.hpp utils/Random.cpp
	g++ -g -c utils/Random.cpp -std=c++11
Point.o : utils/Point.hpp utils/Point.cpp
	g++ -g -c utils/Point.cpp -std=c++11
Utils.o : main.hpp utils/Utils.hpp utils/Utils.cpp
	g++ -g -c utils/Utils.cpp -std=c++11
GameDataDao.o : main.hpp dao/GameData.hpp dao/GameDataDao.hpp dao/GameDataDao.cpp
	g++ -g -c dao/GameDataDao.cpp -std=c++11
ScoreAndTip.o : main.hpp entry/ScoreAndTip.hpp entry/ScoreAndTip.cpp
	g++ -g -c entry/ScoreAndTip.cpp -std=c++11
Chess.o : main.hpp entry/Chess.hpp entry/Chess.cpp
	g++ -g -c entry/Chess.cpp -std=c++11
Chessboard.o : main.hpp entry/Chessboard.hpp entry/Chessboard.cpp
	g++ -g -c entry/Chessboard.cpp -std=c++11
GameView.o : main.hpp game/GameView.hpp game/GameView.cpp
	g++ -g -c game/GameView.cpp -std=c++11
clean:
	rm main.o Random.o Point.o Utils.o GameDataDao.o ScoreAndTip.o Chess.o Chessboard.o GameView.o