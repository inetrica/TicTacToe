#include "Block.h"
#include "Board.h"
#include <iostream>

int main(){

    Board *brd = new Board();
    brd->printBoard();

    brd->setBlock(0, 0, Block::Opt_X);
    brd->printBoard();

    brd->setBlock(1, 1, Block::Opt_O);
    brd->printBoard();


    std::cout << "Bye" << std::endl;
    delete brd;
    return 0;
}
