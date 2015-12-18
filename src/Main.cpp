#include <SFML/Graphics.hpp>

#include "Block.h"
#include "Board.h"
#include "MainMenu.h"

#include <iostream>
#include <limits>

int
main(){

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        window.display();
    }

    return 0;

}
