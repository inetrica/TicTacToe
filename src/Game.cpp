#include "Game.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
 * default to Easy Singleplayer mode,
 * Player places X, ai places O
 * 3x3
 * general tic tac toe game
 */
Game::
Game(){
	state = new GameState(GameState::Easy, GameState::SinglePlayer, 3);
	p1 = new Player(Block::Opt_X, false);
	p2 = new Player(Block::Opt_O, true);
}

Game::
Game(GameState * gs){
	state = gs;
	p1 = new Player(Block::Opt_X, false);
	if(gs->getGameMode() == GameState::SinglePlayer){
		p2 = new Player(Block::Opt_O, true);
	} else {
		p2 = new Player(Block::Opt_O, false);
	}
}

Game::
~Game(){
	delete p1;
	delete p2;
	delete state;
}

int Game::
getBoardSize() const {
	return state->getBoard()->getSize();
}

void Game::
switchPlayer(Player *& curr){
	if(curr == p1) 
		curr = p2;
	else 
		curr = p1;
}

/*
 * return true if the game is over, either via a player winning
 * or the board filling up to a draw
 */
bool Game::
isGameOver(const Board* board, const Player* currPlayer) const{
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

/*
 * First checks if the game is over. if it is, obviously someone
 * made a move, since the last time we checked, the game wasn't over
 * if the game is over, close the window
 *
 * Checks to see if the current player made a move. If he did,
 * end his turn, switch players
 */
void Game::
finishTurn(sf::RenderWindow & window, const Board * board, 
		Player*& curr, const int moveMade){

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
loop(){
	Player * currPlayer = p1;
	int moveMade = -1;

	/*
	 * start by grabbing the window, then drawing it
	 */
	sf::RenderWindow window(sf::VideoMode(BLOCK_SZ*getBoardSize(), BLOCK_SZ*getBoardSize()), "Tic Tac Toe");
	state->drawBoard(window);

	while(window.isOpen()){
		moveMade = -1;

		//Get the current player's move. if a move was made successfully,
		//moveMade will == 0
		moveMade = currPlayer->makeMove(window, state);

		// redraw the board on each loop cycle
		state->drawBoard(window);

		finishTurn(window, state->getBoard(), currPlayer, moveMade);

	}

}
