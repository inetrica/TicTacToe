#include "Board.h"
#include <stdio.h>

Board::Board(){
    size = 3;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
    }
}

Board::Board(int size){
    this.size = size;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
    }
}

Board::~Board(){
    for(int i = 0; i < size; i++){
        delete[] board[i]
    }   
    delete[] board;
}

void Block::setBlock(int row, int col, blockOption val){
    board[row][col] = val;
}

void Block::printBoard(){
    std::cout << "#########" << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << "#";
        for(int j = 0; j < size; j++){
            std::cout << board[i][j].blockToChar() << "#";
        }
        std::cout << std::endl;
    }
    std::cout << "#########" << std::endl;
}
