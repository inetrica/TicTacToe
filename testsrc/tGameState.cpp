#include "GameState.h"
#include "TestBase.h"

void
testDefaultConstructorValues(){
	GameState gs;
	//test default
	assert("Default size 3x3", gs.getBoard()->getSize() == 3);
	assert("Default GameMode SinglePlayer", gs.getGameMode() == GameState::SinglePlayer);
	assert("Default Difficulty Easy", gs.getDifficulty() == GameState::Easy);
}

int main(){

	testDefaultConstructorValues();

	return 0;
}
