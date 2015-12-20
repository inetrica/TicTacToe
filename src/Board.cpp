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
	bool match = true;
	Block::blockOption prev = Block::Opt_E;


	if((prev = board[0][0].getVal()) != Block::Opt_E){
		match = true;
		for(int i = 1; i < size; i++){
			if(prev != board[i][i].getVal()){
				match = false;
				break;
			}
		}
		if(match) return prev;
	}

	if((prev = board[0][size - 1].getVal()) != Block::Opt_E){
		match = true;
		int i = 1;
		int j = size - 2;
		for(; i < size && j > 0; i++, j--){
			if(prev != board[i][j].getVal()){
				match = false;
				break;
			}
		}
		if(match) return prev;
	}


	//check rows
	for(int i = 0; i < size; i++){
		match = true;
		if((prev = board[i][0].getVal()) == Block::Opt_E) continue;
		for(int j = 1; j < size; j++){
			if(prev != board[i][j].getVal()){
				match = false;
				break;
			}
		}
		if(match) return prev;
	}

	//check cols
	for(int i = 0; i < size; i++){
		match = true;
		if((prev = board[0][i].getVal()) == Block::Opt_E) continue;
		for(int j = 1; j < size; j++){
			if(prev != board[j][i].getVal()){
				match = false;
				break;
			}
		}
		if(match) return prev;
	}
	
	return Block::Opt_E;
}
