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



int
main(){
	testBoardInit();

	return 0;

}
