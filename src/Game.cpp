#include "Game.h"

Game::Game(){
	Game(SinglePlayer, Easy);
}

Game::Game(gamemode mode, difficulty diff){
	_gamemode = mode;
	_difficulty = diff;
}

Game::~Game(){

}

void easySingle(sf::RenderWindow & window){
	
}

void hardSingle(sf::RenderWindow & window){
	std::cout << "hard" << std::endl;
}

void pvp(sf::RenderWindow & window){
	std::cout << "pvp" << std::endl;
}

void Game::loop(sf::RenderWindow & window){
	if(_gamemode == SinglePlayer){
		if(_difficulty == Easy){
		
		} else { //Difficulty == hard 
			hardSingle(window);
		}
	
	} else { //2 Player mode
		pvp(window);
	}
}
