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
getMark() const {
	return playerMark;
}

bool Player::
isAI() const{
	return ai;
}

int Player::
makeMove(sf::RenderWindow & window, /*Board *& board,*/ GameState * gs) const{
	if(ai){
		return makeAiMove(/*gs->getBoard(), gs->getDifficulty()*/gs);
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
makeAiMove(/*Board * board, GameState::Difficulty difficulty*/GameState *& gs) const{
	
	//AI needs to first know where he is allowed to place a mark
	//first
	std::vector<int> empty_slots = gs->getEmptySlots();
	GameState::Difficulty difficulty = gs->getDifficulty();

	int slot;
	if(difficulty == GameState::Easy){
		slot = calculateRandomMove(empty_slots);
	} else {//TODO obviousy redundant, eventually after implementing Medium/Hard modes, update this
		slot = calculateMinMax(gs->getBoard(), playerMark);
		if(slot < 0){
			slot = calculateRandomMove(empty_slots);
		}
	}
	int boardSize = gs->getBoard()->getSize();
	int row = slot/boardSize;
	int col = slot%boardSize;
	return gs->getBoard()->setBlock(row, col, playerMark);
}

//handle user mouse click
//return 0 if successful, -1 if unsuccessful
int Player::
makeUserMove(sf::RenderWindow & window, Board * board) const{

	sf::Event event;
	int moveMade = -1;
	while(moveMade < 0 && window.isOpen()){
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
handleUserClick(int mouseX, int mouseY, Board * board) const{
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
calculateRandomMove(std::vector<int> slots) const{
	/*
	 * choose one of the blocks from the vector at random
	 */
	srand(time(NULL));
	int index = rand() % slots.size();
	
	return slots.at(index);
}

int Player::
calculateMinMax(const Board * board, Block::blockOption mark) const{
	StateEvaluator se(board);
	se.calcBestMove(mark, 3);
	return se.getBestMove();
}
