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

		Block::blockOption getBlockValueAt(int row, int col);

		int getNumEmptySlots();

        void draw(sf::RenderWindow & window);

		Block::blockOption checkWinCondition();

	private:
        Block **board;
        int size;
        int numEmptySlots;


};

#endif
