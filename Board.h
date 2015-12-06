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

        void setBlock(int row, int col, blockOption val);

        void printBoard();
}
