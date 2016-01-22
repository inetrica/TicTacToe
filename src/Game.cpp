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
getBoardSize(){
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
finishTurn(sf::RenderWindow & window, Board * board, 
		Player*& curr, int moveMade){
	/*
	* Draw board to the screen
	*/
	/*
	window.clear();
	board->draw(window);
	window.display();
	*/

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
	int moveMade = -1;

	while(window.isOpen()){

		moveMade = currPlayer->makeMove(window, state);

		window.clear();
		state->getBoard()->draw(window);
		window.display();

		finishTurn(window, state->getBoard(), currPlayer, moveMade);

	}

}
