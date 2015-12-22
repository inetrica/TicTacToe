
#include "Block.h"

class Player{
	public:
		Player();
		Player(Block::blockOption mark, bool ai);
		~Player();

		Block::blockOption getMark();
		bool isAI();

	private:
		Block::blockOption playerMark;
		bool ai;
};
