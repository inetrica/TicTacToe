#include "MainMenu.h"

MainMenu::MainMenu(){
	gs = new GameState();
}

MainMenu::~MainMenu(){
	//Don't Delete GameState Here...
	//We pass it on to Game, delete it there
	//TODO revisit where deletion of GameState pointer occurs
}

GameState * MainMenu::getGameState(){
	return gs;
}

void MainMenu::runLoop(){

}
