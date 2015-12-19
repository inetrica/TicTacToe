#include <SFML/Graphics.hpp>

#include "Block.h"
#include "Board.h"
#include "MainMenu.h"

#include <iostream>
#include <stdlib.h>

#define BOARD_SZ 3

int
main(){

	sf::RenderWindow window(sf::VideoMode(BLOCK_SZ*BOARD_SZ, BLOCK_SZ*BOARD_SZ), "Tic Tac Toe");
	if(textures::load() < 0){
		std::cout << "Error loading textures" << std::endl;
		exit(-1);
	}

	Board* board = new Board(BOARD_SZ);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		board->draw(window);
        window.display();
        
    }

    delete board;

    return 0;

}
