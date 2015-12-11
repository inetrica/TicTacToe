#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(){
	active = false;
	_gamemode = SinglePlayer;
	_difficulty = Easy;
}

MainMenu::gamemode
MainMenu::getGamemode(){
	return _gamemode;
}

MainMenu::difficulty
MainMenu::getDifficulty(){
	return _difficulty;
}

int
MainMenu::readInput(MainMenu::gamemode &mode, MainMenu::difficulty &diff){

	int diffic = -1;
	int gmode = -1;

	std::cout << "Please enter 1 for single player, 2 for two player: " << std::flush;

	while (!(std::cin >> gmode) && (gmode < 1 || 2 < gmode)){
		std::cin.clear();
    	std::cin.ignore(10000, '\n');
		std::cout << "Invalid input, please try again. Enter 1 or 2: " << std::flush;
	}


	std::cout << "Please enter 1 for easy mode, 2 for hard mode: " << std::flush;

	while (!(std::cin >> diffic) && (diffic < 1 || 2 < diffic)){
		std::cin.clear();
    	std::cin.ignore(10000, '\n');
		std::cout << "Invalid input, please try again. Enter 1 or 2: " << std::flush;
	}

	switch(gmode){
		case 1:
			mode = SinglePlayer;
			break;
		case 2:
			mode = TwoPlayer;
			break;
		default:
			return -1;
	}

	switch(diffic){
		case 1:
			diff = Easy;
			break;
		case 2:
			diff = Medium;
			break;
		default:
			return -1;
	}
    
    return 0;

}

void
MainMenu::runMainMenu(){
	active = true;

	while(active){//let user pick game mode
		if(MainMenu::readInput(_gamemode, _difficulty) == 0){
			active = false;
		}
	}

}
