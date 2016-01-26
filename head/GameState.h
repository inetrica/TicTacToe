#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Board.h"
#include <vector>

class GameState{
	public:

		/*
		 * SinglePlayer = 1 User vs AI
		 * TwoPlayer = 2 Users
		 */
		enum GameMode{
			SinglePlayer,
			TwoPlayer
		};

		/*
		 * Easy = AI will use easy function to calculate next move (Easy is at random)
		 * Medium = AI will use medium function to calculate next move (still need to implement, AlphaBeta/MinMax alg?)
		 */
		enum Difficulty{
			Easy,
			Medium
		};

		GameState();
		GameState(Difficulty d, GameMode gm, int sz);
		~GameState();

		GameMode getGameMode();
		Difficulty getDifficulty();
		Board * getBoard();

		std::vector<int> getEmptySlots();

		void drawBoard(sf::RenderWindow & window);

	private:
		GameMode gamemode;
		Difficulty difficulty;
		Board * board;
};

#endif
