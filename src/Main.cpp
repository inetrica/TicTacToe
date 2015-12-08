#include "Block.h"
#include "Board.h"
#include <iostream>
#include <limits>

int
readInput(int & row, int & col){
    char ch;
    
    //get first int
    if(!(std::cin >> row))
        return -1;

    //skip through whitespace
    std::cin.get(ch);
    while(ch == ' ' || ch == '\t')
        std::cin.get(ch);

    if(ch != ',') return -1;

    //get second int
    if(!(std::cin >> col))
        return -1;

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    return 0;

}

int
main(){

    Board *brd = new Board();
    brd->printBoard();

    while(1){
        int toRow, toCol;


        std::cout << "Where would you like to place a mark?\nPlease separate values with a comma: eg: 0,1 where row = 0, column = 1 >> " << std::flush;
        if(readInput(toRow, toCol) < 0){
            std::cout << "Input Invalid" << std::endl;
            continue;
        }

        brd->setBlock(toRow, toCol, Block::Opt_X);
        std::cout << std::endl;
        brd->printBoard();
    }

    std::cout << "Bye" << std::endl;
    delete brd;
    return 0;
}
