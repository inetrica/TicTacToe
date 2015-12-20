#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include "Board.h"

class Game{
	public:

		enum gamemode{
			SinglePlayer,
			TwoPlayer
		};

		enum difficulty{
			Easy,
			Medium
		};

		Game();
		Game(gamemode mode, difficulty diff, int sz);
		~Game();

		void renderThread(sf::RenderWindow * window, Board * board);

		int getBoardSize();

		void easySingle(sf::RenderWindow & window);

		void hardSingle(sf::RenderWindow & window);

		void pvp(sf::RenderWindow & window);

		void loop();

	private:
		gamemode _gamemode;
		difficulty _difficulty;
		int boardSize;

		std::mutex boardStateMutex;
};

#endif
