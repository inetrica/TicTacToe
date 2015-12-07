#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board
{
    private:
        Block **board;
        int size;
    public:

        Board();
        Board(int size);
        ~Board();

        void setBlock(int row, int col, Block::blockOption val);

        void printBoard();
};

#endif
