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

void Board::printBoard(){
    std::string border = "#############";
    std::string buffsp = "#   #   #   #";
    std::cout << border << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << buffsp << std::endl;
        std::cout << "#";
        for(int j = 0; j < size; j++){
            std::cout << " " << board[i][j].blockToChar() << " #";
        }
        std::cout << std::endl;
        std::cout << buffsp << std::endl;
        std::cout << border << std::endl;
    }
}
