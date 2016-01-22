
#include "Board.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>


class Player{
	public:
		Player();
		Player(Block::blockOption mark, bool ai);
		~Player();

		/*
		 * get the blockOption assigned to this player
		 * (is he using X or O on the board)
		 */
		Block::blockOption getMark();

		int makeMove(sf::RenderWindow & window, GameState *& gs);
		/*
		 * return true if this Player object does not represent a human user
		 */
		bool isAI();

	private:
		Block::blockOption playerMark;
		bool ai;

		int makeAiMove(Board *& board, GameState::Difficulty difficulty);
		int makeUserMove(sf::RenderWindow & window, Board *& board);

		//Calculate the next move for AI by choosing randomly from open slots
		int calculateRandomMove(Board * board);
		//handle user mouse click
		int handleUserClick(int mouseX, int mouseY, Board *& board);
};
