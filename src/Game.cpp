#include "Game.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <time.h>

/*
 * default to Easy Singleplayer mode,
 * Player places X, ai places O
 * 3x3
 * general tic tac toe game
 */
Game::
Game(){
	_gamemode = SinglePlayer;
	_difficulty = Easy;
	p1 = new Player(Block::Opt_X, false);
	p2 = new Player(Block::Opt_O, true);
	boardSize = 3;
}

Game::
Game(gamemode mode, difficulty diff, int sz){
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

Game::
~Game(){
	delete p1;
	delete p2;
}

int Game::
getBoardSize(){
	return boardSize;
}

void Game::
switchPlayer(Player *& curr){
	if(curr == p1) 
		curr = p2;
	else 
		curr = p1;
}

int Game::
calculateRandomMove(){
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

/*
 * handle user mouse click on board
 * return 0 if move was made successfully, -1 otherwise
 */
int Game::
handleUserClick(int mouseX, int mouseY, Player* currPlayer){
	//If the mouse position is out of bounds, don't do anything
	if(mouseX < 0 || mouseX > BLOCK_SZ*boardSize 
			|| mouseY < 0 || mouseY > BLOCK_SZ*boardSize) return -1;
	int col = mouseX/BLOCK_SZ; //determine which column by dividing the x position by the size of a block
	int row = mouseY/BLOCK_SZ; //determine which row by dividing the y position by the size of a block
	if(row > boardSize || col > boardSize) return -1;
	return board->setBlock(row, col, currPlayer->getMark());
}

/*
 * handle ai desired move
 * return 0 if move was made successfully, -1 otherwise
 */
int Game::
handleAiMove(int slot, Player* currPlayer){
	int row = slot/boardSize;
	int col = slot%boardSize;
	return board->setBlock(row, col, currPlayer->getMark());
}

/*
 * return true if the game is over, either via a player winning
 * or the board filling up to a draw
 */
bool Game::
isGameOver(Board* board, Player* currPlayer){
	Block::blockOption winner = board->checkWinCondition();
	
	/*
	* if someone won, game ends
	* if board fills up, game ends
	*/
	if(winner != Block::Opt_E){
		std::cout << "Congratulations!" << std::endl;
		std::cout << "Player " 
			<< Block::blockOptionToChar(currPlayer->getMark())
			<< " Wins!" << std::endl;
		return true;
	} else if (board->getNumEmptySlots() <= 0){
		std::cout << "Stalemate!" << std::endl;
		return true;
	}
	
	return false;
}

void Game::
finishTurn(sf::RenderWindow & window, Board* board, 
		Player*& curr, int moveMade){
	/*
	* Draw board to the screen
	*/
	window.clear();
	board->draw(window);
	window.display();

	if(isGameOver(board, curr)){
		sleep(1);
		window.close();
	}

	/*
	* if the current player made a move, switch to the other player
	*/
	if(moveMade == 0){
		sf::sleep(sf::milliseconds(300));
		switchPlayer(curr);
	}
}

void Game::
loop(sf::RenderWindow & window){
	Player * currPlayer = p1;
	board = new Board(boardSize);
	bool won = false;

	while(window.isOpen() && !won){
		int moveMade = -1;
		//if(p1Turn || (!p1Turn && !(p2->isAI()))){
		if(!(currPlayer->isAI())){
			/*
			 * sfml documentation says it is safer to keep pollEvent in one main loop,
			 * i'll leave it like this then for now
			 */
			sf::Event event;
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
						moveMade = handleUserClick(event.mouseButton.x, event.mouseButton.y, currPlayer);
					default:
						//do nothing
						break;
				}
				//clear the queue, otherwise player can queue up moves
				while(window.pollEvent(event));
			}
		} else { //ai option
			if(_difficulty == Easy){ //"Easy" mode is just random choice
				int slot = calculateRandomMove();
				moveMade = handleAiMove(slot, currPlayer);
			}
		}

		finishTurn(window, board, currPlayer, moveMade);

	}

	delete board;

}
