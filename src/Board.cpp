#include "Board.h"
#include <iostream>

Board::
Board(){
    size = 3;
    numEmptySlots = size * size;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
        for(int j = 0; j < size; j++){
			 board[i][j].setPos(j*BLOCK_SZ, i*BLOCK_SZ);
        }
    }
}

Board::
Board(const int size){
    if(size <= 0){
        std::cout << "Invalid size when trying to create Board" << std::endl;
    }
    this->size = size;
    numEmptySlots = size * size;
    board = new Block*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Block[size];
    	for(int j = 0; j < size; j++){
			 board[i][j].setPos(j*BLOCK_SZ, i*BLOCK_SZ);
        }
    }
}

Board::
~Board(){
    for(int i = 0; i < size; i++){
        delete[] board[i];
    }   
    delete[] board;
}

int const Board::
setBlock(const int row, const int col, const Block::blockOption val){
	//Make sure row & col are within bounds
    if(size <= row || size <= col || row < 0 || col < 0){
        std::cout << row << ", " << col << " is not a valid position" << std::endl;
        return -1;
    } else {
    	if(board[row][col].getVal() != Block::Opt_E){ //If the block on the board is not empty, don't replace the value already there
    		return -2;
    	}
        board[row][col].setVal(val);
    }
    if(val != Block::Opt_E)
    	numEmptySlots--;
    else
    	numEmptySlots++;
    return 0;
}

int Board::getSize() const {
	return size;
}

Block::blockOption Board::
getBlockValueAt(const int row, const int col) const {
	return board[row][col].getVal();
}

int Board::
getNumEmptySlots() const {
	return numEmptySlots;
}

/*
 * draw the board, block by block
 */
void Board::
draw(sf::RenderWindow & window) const {
	window.clear();
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			window.draw(board[i][j].getSprite());
		}
	}
	window.display();
}

/*
 * return Opt_E if nobody's won, otherwise return the winner
 */
Block::blockOption Board::
checkWinCondition() const {
	Block::blockOption checkResult = Block::Opt_E;

	//Check Diagonals
	if((checkResult = checkDiagonalWC()) != Block::Opt_E){
		return checkResult;
	}

	//Check Rows
	if((checkResult = checkRowWC()) != Block::Opt_E){
		return checkResult;
	}

	//Check Columns
	return checkColWC();

}

/*
 * check if someone has 3 diagonally, if so return the blockOption which won,
 * otherwise return the empty blockOption
 */
Block::blockOption Board::
checkDiagonalWC() const {
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
		for(; i < size && j >= 0; i++, j--){
			if(prev != board[i][j].getVal()){
				match = false;
				break;
			}
		}
		if(match) return prev;
	}

	return Block::Opt_E;
}

/*
 * Check if someone has 3 in a row, if so, return the blockOption which has 3 in a row,
 * otherwise return the empty blockOption
 */
Block::blockOption Board::
checkRowWC() const {
	Block::blockOption prev = Block::Opt_E;

	for(int i = 0; i < size; i++){
		bool match = true;
		if((prev = board[i][0].getVal()) == Block::Opt_E) continue;
		for(int j = 1; j < size; j++){
			if(prev != board[i][j].getVal()){
				match = false;
				break;
			}
		}
		if(match) return prev;
	}

	return Block::Opt_E;
}

/*
 * Check if someone has 3 in a column, if so, return the blockOption which has 3 in a column,
 * otherwise return the empty blockOption
 */
Block::blockOption Board::
checkColWC() const {
	//bool match = true;
	Block::blockOption prev = Block::Opt_E;

	for(int i = 0; i < size; i++){
		bool match = true;
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
