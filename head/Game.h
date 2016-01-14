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
		 * main game loop
		 */
		void loop(sf::RenderWindow & window);

	private:
		gamemode _gamemode;
		difficulty _difficulty;
		int boardSize;
		Player *p1;
		Player *p2;
		Board *board;

		/*
		 * if curr points to p1, switch it to p2
		 * if curr points to p2, switch it to p1
		 */
		void switchPlayer(Player *& curr);

		//Calculate the next move for AI by choosing randomly from open slots
		int calculateRandomMove();
		//handle user mouse click
		int handleUserClick(int mouseX, int mouseY, Player* currPlayer);
		//handle ai move after calculating block with value <slot>
		//slots are numbered in the following manner
		// 0 | 1 | 2
		// 3 | 4 | 5
		// 6 | 7 | 8 
		// Therefore, from slot 7, determine row by doing slot/boardSize
		// 						   determine col by doing slot%boardSize
		int handleAiMove(int slot, Player* currPlayer);

		/*
		 * finish the turn by drawing the board,
		 * check if the game is over, switch the currentPlayer
		 */
		void finishTurn(sf::RenderWindow & window, Board* board,
				Player*& curr, int moveMade);

		bool isGameOver(Board* board, Player* currPlayer);

};

#endif
