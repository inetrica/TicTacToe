#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

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

		int getBoardSize();

		void switchPlayer(Player *& curr);

		int chooseEasy();

		void hardSingle(sf::RenderWindow & window);

		void pvp(sf::RenderWindow & window);

		void loop(sf::RenderWindow & window);

	private:
		gamemode _gamemode;
		difficulty _difficulty;
		int boardSize;
		Player *p1;
		Player *p2;
		Board *board;
};

#endif
