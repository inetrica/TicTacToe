#include "Board.h"
#include <iostream>

Board::Board(){
    size = 3;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
    }
}

Board::Board(int size){
    if(size <= 0){
        std::cout << "Invalid size when trying to create Board" << std::endl;
    }
    this->size = size;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
    }
}

Board::~Board(){
    for(int i = 0; i < size; i++){
        delete[] board[i];
    }   
    delete[] board;
}

int Board::setBlock(int row, int col, Block::blockOption val){
    if(size <= row || size <= col || row < 0 || col < 0){
        std::cout << row << ", " << col << " is not a valid position" << std::endl;
        return -1;
    } else {
        board[row][col].setVal(val);
    }
    return 0;
}
