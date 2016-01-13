#include "Board.h"
#include "TestBase.h"

void
testBoardInit(){
	Board board;
	int expectSize = 3;
	assert("TestBoardInitSize", board.getSize() == expectSize);
	assert("TestBoardAllEmpty", board.getNumEmptySlots() == expectSize*expectSize);

	for(int i = 0; i < expectSize; i++){
		for(int j = 0; j < expectSize; j++){
			assert("TestEachBlockOnBoardEmpty" , board.getBlockValueAt(i, j) == Block::Opt_E);
		}
	}

	std::cout << std::endl;
}

void
testSetBlockOnBoard(){
	Board board;
	int numSlots = board.getSize()*board.getSize();
	//check initially empty
	assert("TestRow0Col1 Empty", board.getBlockValueAt(0,1) == Block::Opt_E);

	//check number of empty slots should be size*size
	assert("9 Empty Slots", board.getNumEmptySlots() == numSlots);
	
	//set empty block to X, check block is X
	assert("TestSetRow0Col1 To X", 0 == board.setBlock(0, 1, Block::Opt_X));
	assert("TestRow0Col1 is X", board.getBlockValueAt(0, 1) == Block::Opt_X);
	numSlots--;

	//check number of empty slots should now be starting size - 1
	assert("8 Empty Slots", board.getNumEmptySlots() == numSlots);

	//try to set block from X to O, should fail with return value -2, should still be set to X
	assert("TestSetRow0Col1 To O fails", -2 == board.setBlock(0, 1, Block::Opt_O));
	assert("TestRow0Col1 still X", board.getBlockValueAt(0, 1) == Block::Opt_X);

	//check number of empty slots should still be starting size - 1
	assert("Still 8 Empty Slots", board.getNumEmptySlots() == numSlots);

}

/**
 * x--
 * -x-
 * --x
 * checkWinCondition() should return Opt_X
 */
void
checkDiagonalL2R(){
	Board board;

	board.setBlock(0,0, Block::Opt_X);
	assert("x--\n---\n---\nNo winner", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(1, 1, Block::Opt_X);
	assert("x--\n-x-\n---\nNo winner", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(2, 2, Block::Opt_X);
	assert("x--\n-x-\n--x\n X winner", 
			board.checkWinCondition() == Block::Opt_X);
}

/**
 * --x
 * -x-
 * x--
 * checkWinCondition() should return Opt_O
 */
void
checkDiagonalR2L(){
	Board board;

	board.setBlock(0,2, Block::Opt_O);
	assert("--o\n---\n---\nNo winner", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(1, 1, Block::Opt_O);
	assert("--o\n-o-\n---\nNo winner", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(2, 0, Block::Opt_O);
	assert("--o\n-o-\no--\n O winner", 
			board.checkWinCondition() == Block::Opt_O);
}

/**
 * xxx
 * ---
 * ---
 * checkWinCondition() should return Opt_X
 */
void
checkFirstRow(){
	Board board;

	board.setBlock(0, 0, Block::Opt_X);
	assert("x--\n---\n---", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(0, 1, Block::Opt_X);
	assert("xx-\n---\n---", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(0, 2, Block::Opt_X);
	assert("xxx\n---\n---", 
			board.checkWinCondition() == Block::Opt_X);
}

/**
 * ---
 * ---
 * ooo
 * checkWinCondition() should return Opt_O
 */
void
checkLastRow(){
	Board board;

	board.setBlock(2, 0, Block::Opt_O);
	assert("---\n---\no--", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(2, 1, Block::Opt_O);
	assert("---\n---\noo-", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(2, 2, Block::Opt_O);
	assert("---\n---\nooo", 
			board.checkWinCondition() == Block::Opt_O);
}

/**
 * x--
 * x--
 * x--
 * checkWinCondition() should return Opt_X
 */
void
checkFirstCol(){
	Board board;

	board.setBlock(0, 0, Block::Opt_X);
	assert("x--\n---\n---", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(1, 0, Block::Opt_X);
	assert("x--\nx--\n---", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(2, 0, Block::Opt_X);
	assert("x--\nx--\nx--", 
			board.checkWinCondition() == Block::Opt_X);
}

/**
 * --o
 * --o
 * --o
 * checkWinCondition() should return Opt_O
 */
void
checkLastCol(){
	Board board;

	board.setBlock(0, 2, Block::Opt_O);
	assert("--o\n---\n---", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(1, 2, Block::Opt_O);
	assert("--o\n--o\n---", 
			board.checkWinCondition() == Block::Opt_E);

	board.setBlock(2, 2, Block::Opt_O);
	assert("--o\n--o\n--o", 
			board.checkWinCondition() == Block::Opt_O);
}

int
main(){
	testBoardInit();

	testSetBlockOnBoard();

	checkDiagonalL2R();
	checkDiagonalR2L();

	checkFirstRow();
	checkLastRow();

	checkFirstCol();
	checkLastCol();

	return 0;

}
