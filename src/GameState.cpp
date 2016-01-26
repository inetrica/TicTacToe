#include "GameState.h"

GameState::
GameState(){
	gamemode = SinglePlayer;
	difficulty = Easy;
	board = new Board(3);
}

GameState::
GameState(Difficulty d, GameMode gm, int sz){
	gamemode = gm;
	difficulty = d;
	board = new Board(sz);
}

GameState::
~GameState(){
	delete board;
}

GameState::GameMode GameState::
getGameMode(){
	return gamemode;
}

GameState::Difficulty GameState::
getDifficulty(){
	return difficulty;
}

Board * GameState::
getBoard(){
	return board;
}

std::vector<int> GameState::
getEmptySlots(){
	std::vector<int> slots;
	int boardSize = board->getSize();
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			if(board->getBlockValueAt(i, j) == Block::Opt_E)
				slots.push_back(i*3 + j);
		}
	}
	return slots;
}

void GameState::drawBoard(sf::RenderWindow & window){
	window.clear();
	board->draw(window);
	window.display();
}
