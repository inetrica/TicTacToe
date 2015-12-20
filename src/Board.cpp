#include "Board.h"
#include <iostream>

Board::Board(){
    size = 3;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
        for(int j = 0; j < size; j++){
			 board[i][j].setPos(j*BLOCK_SZ, i*BLOCK_SZ);
        }
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
    	for(int j = 0; j < size; j++){
			 board[i][j].setPos(j*BLOCK_SZ, i*BLOCK_SZ);
        }
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

void Board::draw(sf::RenderWindow & window){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			window.draw(board[i][j].getSprite());
		}
	}
}

/*
 * return Opt_E if nobody's won, otherwise return the winner
 */
Block::blockOption Board::checkWinCondition(){
	bool matchRow = true;
	bool matchCol = true;

	//check diagonals
	if((board[0][0].getVal() == board[1][1].getVal() && board[1][1].getVal() == board[2][2].getVal()) ||
			(board[0][2].getVal() == board[1][1].getVal() && board[1][1].getVal() == board[2][0].getVal())){
		return board[1][1].getVal();
	}



	//check rows and columns
	for(int i = 0; i < size; i++){
		matchRow = true;
		matchCol = true;
		Block::blockOption row = board[i][0].getVal();
		Block::blockOption col = board[0][i].getVal();
		for(int j = 1; j < size; j++){
			
			//row
			if(matchRow && board[i][j].getVal() == row){
				matchRow = false;
			}
			row = board[i][j].getVal();

			//col
			if(matchCol && board[j][i].getVal() == col){
				matchCol = false;
			}
			col = board[j][i].getVal();
		}
		if(matchRow) return row;
		if(matchCol) return col;
	}
	return Block::Opt_E;
}
