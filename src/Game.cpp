#include "Game.h"

#include <iostream>
#include <stdlib.h>

Game::Game(){
	_gamemode = SinglePlayer;
	_difficulty = Easy;
	boardSize = 3;
}

Game::Game(gamemode mode, difficulty diff, int sz){
	_gamemode = mode;
	_difficulty = diff;
	boardSize = sz;
}

Game::~Game(){

}

int Game::getBoardSize(){
	return boardSize;
}

void Game::easySingle(sf::RenderWindow & window){
	Board * board = new Board(boardSize);

	//TODO EDIT THIS LATER so that we dont check win condition on EVERY step of the loop
	//instead only check wincondition on mouseclick.
	while(window.isOpen() && (board->checkWinCondition() == Block::Opt_E)){
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		board->draw(window);
        window.display();
	}

	delete board;
}

void Game::hardSingle(sf::RenderWindow & window){
	std::cout << "hard" << std::endl;
}

void Game::pvp(sf::RenderWindow & window){
	std::cout << "pvp" << std::endl;
}

void Game::loop(sf::RenderWindow & window){
	if(_gamemode == SinglePlayer){
		if(_difficulty == Easy){
			easySingle(window);
		} else { //Difficulty == hard 
			hardSingle(window);
		}
	
	} else { //2 Player mode
		pvp(window);
	}
}
