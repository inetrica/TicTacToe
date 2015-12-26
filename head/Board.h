#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board
{
    public:

        Board();
        //Size indicating number of blocks per row and column
        Board(int size);
        ~Board();

		//assign the blockOption val to the Block currently at the position pointed to 
		//on the board by the arguments row & col
        int setBlock(int row, int col, Block::blockOption val);

		//return the blockOption currently assigned to the block at the position passed in by the 
		//row & col arguments
		Block::blockOption getBlockValueAt(int row, int col);

		//return the number of empty slots on the board
		int getNumEmptySlots();

		//Draw the board onto the window passed as an argument using SFML's window.draw()
        void draw(sf::RenderWindow & window);

		//Check if someone has won
		//return Opt_E if no winner yet, otherwise return the blockOption of the winner
		Block::blockOption checkWinCondition();

	private:
        Block **board; //The board is set up as a 2d array of Block objects
        int size; //size of the board where units = # of Blocks per row or col
        int numEmptySlots; //track # of empty slots on board

		//Check different ways of winning (3 in a row, 3 in a column, or diagonally
		Block::blockOption checkDiagonalWC();
		Block::blockOption checkRowWC();
		Block::blockOption checkColWC();


};

#endif
