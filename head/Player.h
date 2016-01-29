
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
		Block::blockOption getMark() const;

		int makeMove(sf::RenderWindow & window, GameState * gs) const;
		/*
		 * return true if this Player object does not represent a human user
		 */
		bool isAI() const;

	private:
		Block::blockOption playerMark;
		bool ai;

		int makeAiMove(/*Board * board, GameState::Difficulty difficulty*/GameState *& gs) const;
		int makeUserMove(sf::RenderWindow & window, Board * board) const;

		//Calculate the next move for AI by choosing randomly from open slots
		int calculateRandomMove(std::vector<int> slots) const;
		//handle user mouse click
		int handleUserClick(int mouseX, int mouseY, Board * board) const;
};
