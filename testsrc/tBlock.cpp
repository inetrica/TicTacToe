#include "Block.h"
#include "TestBase.h"

void
testBlockInitEmpty(){
	Block block;
	assert("TestBlockInitEmpty", block.getVal() == Block::Opt_E);
}

void
testSettingBlockVal(){
	Block block;
	block.setVal(Block::Opt_X);
	assert("TestBlockIsX", block.getVal() == Block::Opt_X);
	block.setVal(Block::Opt_O);
	assert("TestBlockIsO", block.getVal() == Block::Opt_O);
	block.setVal(Block::Opt_E);
	assert("TestBlockIsE", block.getVal() == Block::Opt_E);
}

void
testBlockToChar(){
	assert("Test Opt_E is ' '", 
			Block::blockOptionToChar(Block::Opt_E) == ' ');
	assert("Test Opt_X is 'X'",
			Block::blockOptionToChar(Block::Opt_X) == 'X');
	assert("Test Opt_O is 'O'",
			Block::blockOptionToChar(Block::Opt_O) == 'O');
}

int 
main(){
	testBlockInitEmpty();

	testSettingBlockVal();

	testBlockToChar();

	return 0;

}
