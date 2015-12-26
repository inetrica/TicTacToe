#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

class Game{
	public:

		/*
		 * SinglePlayer = 1 User vs AI
		 * TwoPlayer = 2 Users
		 */
		enum gamemode{
			SinglePlayer,
			TwoPlayer
		};

		/*
		 * Easy = AI will use easy function to calculate next move (Easy is at random)
		 * Medium = AI will use medium function to calculate next move (still need to implement, AlphaBeta/MinMax alg?)
		 */
		enum difficulty{
			Easy,
			Medium
		};

		Game();
		Game(gamemode mode, difficulty diff, int sz);
		~Game();

		//Get size of the board in terms of # of blocks in a row or col
		int getBoardSize();

		/*
		 * if curr points to p1, switch it to p2
		 * if curr points to p2, switch it to p1
		 */
		void switchPlayer(Player *& curr);

		//Calculate the next move for AI by choosing randomly from open slots
		int calculateRandomMove();

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
