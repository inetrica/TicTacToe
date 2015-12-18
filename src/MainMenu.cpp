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
