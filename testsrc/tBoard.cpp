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
	//check initially empty
	assert("TestRow0Col1 Empty", board.getBlockValueAt(0,1) == Block::Opt_E);
	
	//set empty block to X, check block is X
	assert("TestSetRow0Col1 To X", 0 == board.setBlock(0, 1, Block::Opt_X));
	assert("TestRow0Col1 is X", board.getBlockValueAt(0, 1) == Block::Opt_X);

	//try to set block from X to O, should fail with return value -2, should still be set to X
	assert("TestSetRow0Col1 To O fails", -2 == board.setBlock(0, 1, Block::Opt_O));
	assert("TestRow0Col1 still X", board.getBlockValueAt(0, 1) == Block::Opt_X);
}



int
main(){
	testBoardInit();

	testSetBlockOnBoard();

	return 0;

}
