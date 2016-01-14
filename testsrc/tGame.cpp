#include "Game.h"
#include "TestBase.h"

void
testDefaultConstructorValues(){
	Game game;
	//test default boardsize
	assert("Default BoardSize is 3", game.getBoardSize() == 3);
}

int main(){

	testDefaultConstructorValues();

	return 0;
}
