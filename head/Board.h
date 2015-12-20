#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board
{
    public:

        Board();
        Board(int size);
        ~Board();

        int setBlock(int row, int col, Block::blockOption val);

        void draw(sf::RenderWindow * window);

		Block::blockOption checkWinCondition();

	private:
        Block **board;
        int size;


};

#endif
