#include <SFML/Graphics.hpp>

//#include "Block.h"
//#include "Board.h"
#include "Game.h"
#include "MainMenu.h"

#include <iostream>
#include <stdlib.h>

int
main(){

	Game game;

	sf::RenderWindow window(sf::VideoMode(BLOCK_SZ*game.getBoardSize(), BLOCK_SZ*game.getBoardSize()), "Tic Tac Toe");
	if(textures::load() < 0){
		std::cout << "Error loading textures" << std::endl;
		exit(-1);
	}

	game.loop(window);


    return 0;

}
