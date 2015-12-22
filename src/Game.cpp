#include "Game.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <time.h>

Game::Game(){
	_gamemode = SinglePlayer;
	_difficulty = Easy;
	p1 = new Player(Block::Opt_X, false);
	p2 = new Player(Block::Opt_O, true);
	boardSize = 3;
}

Game::Game(gamemode mode, difficulty diff, int sz){
	_gamemode = mode;
	p1 = new Player(Block::Opt_X, false);
	if(_gamemode == SinglePlayer){
		p2 = new Player(Block::Opt_O, true);
	} else {
		p2 = new Player(Block::Opt_O, false);
	}
	_difficulty = diff;
	boardSize = sz;
}

Game::~Game(){
	delete p1;
	delete p2;
}

int Game::getBoardSize(){
	return boardSize;
}

int Game::chooseEasy(){
	std::vector<int> slots;
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			slots.push_back(i*3 + j);
		}
	}
	srand(time(NULL));
	int index = rand() % slots.size();
	
	return slots.at(index);
}

void Game::hardSingle(sf::RenderWindow & window){
	std::cout << "hard" << std::endl;
}

void Game::pvp(sf::RenderWindow & window){
	std::cout << "pvp" << std::endl;
}

void Game::loop(sf::RenderWindow & window){
	Board * board = new Board(boardSize);
	Player * currPlayer = p1;
	bool won = false;

	while(window.isOpen() && !won){
		int row, col;
		//if(p1Turn || (!p1Turn && !(p2->isAI()))){
		if(!(currPlayer->isAI())){
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
						col = mouseX/BLOCK_SZ;
						row = mouseY/BLOCK_SZ;
						if(row > boardSize || col > boardSize) break;
						board->setBlock(row, col, currPlayer->getMark());

						}
						break;
					default:
						//do nothing
						break;
				}
			}
		} else { //npc option
			if(_difficulty == Easy){ //"Easy" mode is just random choice
				int slot = chooseEasy();
				row = slot/boardSize;
				col = slot%boardSize;
				board->setBlock(row, col, currPlayer->getMark());
			}
		}

        window.clear();
		board->draw(window);
        window.display();

		Block::blockOption won = board->checkWinCondition();
		if(won != Block::Opt_E){
			std::cout << "Congratulations!" << std::endl;
			std::cout << "Player " << Block::blockOptionToChar(currPlayer->getMark())
				<< " Wins!" << std::endl;
			sleep(1);
			window.close();
		}
	}

	delete board;
}
