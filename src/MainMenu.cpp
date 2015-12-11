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
MainMenu::readInput(){

	char ch;

    //get first int
    if(!(std::cin >> row))
        return -1;

    //skip through whitespace
    std::cin.get(ch);
    while(ch == ' ' || ch == '\t')
        std::cin.get(ch);

    if(ch != ',') return -1;

    //get second int
    if(!(std::cin >> col))
        return -1;

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    return 0;

}

void
MainMenu::runMainMenu(){
	active = true;

	while(active){//let user pick game mode
		
	}

}
