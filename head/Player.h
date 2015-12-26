
#include "Block.h"

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
		/*
		 * return true if this Player object does not represent a human user
		 */
		bool isAI();

	private:
		Block::blockOption playerMark;
		bool ai;
};
