#include "GameState.h"

GameState::
GameState(){
	gamemode = SinglePlayer;
	difficulty = Easy;
	board = new Board(3);
}

GameState::
GameState(const Difficulty d, const GameMode gm, const int sz){
	gamemode = gm;
	difficulty = d;
	board = new Board(sz);
}

GameState::
~GameState(){
	delete board;
}

GameState::GameMode GameState::
getGameMode() const {
	return gamemode;
}

GameState::Difficulty GameState::
getDifficulty() const {
	return difficulty;
}

Board * GameState::
getBoard() const {
	return board;
}

std::vector<int> GameState::
getEmptySlots() const {
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

void GameState::drawBoard(sf::RenderWindow & window) const {
	window.clear();
	board->draw(window);
	window.display();
}
