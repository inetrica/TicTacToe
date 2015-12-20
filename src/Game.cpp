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
	bool won = false;

	//TODO EDIT THIS LATER so that we dont check win condition on EVERY step of the loop
	//instead only check wincondition on mouseclick.
	while(window.isOpen() && !won){
		sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
            	case sf::Event::Closed:
            		window.close();
            		break;
				case sf::Event::MouseButtonPressed:
					{
					int mouseX = event.mouseButton.x;
					int mouseY = event.mouseButton.y;
					std::cout << "x " << mouseX << ", y " << mouseY << std::endl;
					if(mouseX < 0 || mouseX > BLOCK_SZ*boardSize || mouseY < 0 || mouseY > BLOCK_SZ*boardSize) break;
					int col = mouseX/BLOCK_SZ;
					int row = mouseY/BLOCK_SZ;
					if(row > boardSize || col > boardSize) break;
					board->setBlock(row, col, Block::Opt_X);

					won = (board->checkWinCondition() != Block::Opt_E);
					}
					break;
				default:
					//do nothing
					break;
            }
        }

        window.clear();
		board->draw(window);
        window.display();

		if(won){
			std::cout << "Congratulations!" << std::endl;
			window.close();
		}
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
