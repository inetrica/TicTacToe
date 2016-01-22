#include "Player.h"

Player::
Player(){
	playerMark = Block::Opt_X;
	ai = false;
}

Player::
Player(Block::blockOption mark, bool ai){
	playerMark = mark;
	this->ai = ai;
}

Player::
~Player(){

}

Block::blockOption Player::
getMark(){
	return playerMark;
}

bool Player::
isAI(){
	return ai;
}

int Player::
makeMove(sf::RenderWindow & window, /*Board *& board,*/ GameState *& gs){
	if(ai){
		return makeAiMove(gs->getBoard(), gs->getDifficulty());
	} else {
		return makeUserMove(window, gs->getBoard());
	}
}

//handle ai move after calculating block with value <slot>
//slots are numbered in the following manner
// 0 | 1 | 2
// 3 | 4 | 5
// 6 | 7 | 8 
// Therefore, from slot 7, determine row by doing slot/boardSize
// 						   determine col by doing slot%boardSize
// Return 0 if succesful, -1 if unsuccessful
int Player::
makeAiMove(Board *& board, GameState::Difficulty difficulty){
	int slot;
	if(difficulty == GameState::Easy){
		slot = calculateRandomMove(board);
	} else {//TODO obviousy redundant, eventually after implementing Medium/Hard modes, update this
		slot = calculateRandomMove(board);
	}
	int boardSize = board->getSize();
	int row = slot/boardSize;
	int col = slot%boardSize;
	return board->setBlock(row, col, playerMark);
}

//handle user mouse click
//return 0 if successful, -1 if unsuccessful
int Player::
makeUserMove(sf::RenderWindow & window, Board *& board){

	sf::Event event;
	int moveMade = -1;
	while(moveMade < 0){
		while (window.pollEvent(event) /*&& moveMade < 0*/)
		{
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					//only register the first move made by player,
					//otherwise player might be able to make multiple moves in a turn
					if(moveMade == 0) break;
					moveMade = handleUserClick(event.mouseButton.x, event.mouseButton.y, board);
					break;
				default:
					//do nothing
					break;
			}
			//clear the queue, otherwise player can queue up moves
			while(window.pollEvent(event));
		}
	}

	return moveMade;
}

int Player::
handleUserClick(int mouseX, int mouseY, Board *& board){
	int boardSize = board->getSize();
	//If the mouse position is out of bounds, don't do anything
	if(mouseX < 0 || mouseX > BLOCK_SZ*boardSize 
			|| mouseY < 0 || mouseY > BLOCK_SZ*boardSize) return -1;
	int col = mouseX/BLOCK_SZ; //determine which column by dividing the x position by the size of a block
	int row = mouseY/BLOCK_SZ; //determine which row by dividing the y position by the size of a block
	if(row > boardSize || col > boardSize) return -1;
	return board->setBlock(row, col, playerMark);
}

//Calculate the next move for AI by choosing randomly from open slots
int Player::
calculateRandomMove(Board * board){

	int boardSize = board->getSize();
	/*
	 * go through board and add empty blocks to this vector
	 */
	std::vector<int> slots;
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			if(board->getBlockValueAt(i, j) == Block::Opt_E)
				slots.push_back(i*3 + j);
		}
	}

	/*
	 * choose one of the blocks from the vector at random
	 */
	srand(time(NULL));
	int index = rand() % slots.size();
	
	return slots.at(index);
}
