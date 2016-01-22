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
