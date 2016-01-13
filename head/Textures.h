#ifndef TEXTURES_H
#define TEXTURES_H

#include <SFML/Graphics.hpp>

/*
 * use this namespace to load the textures needed for the game
 */
namespace textures{
		int load();

		//Textures for blocks: set texture to either x, o, or empty
		extern sf::Texture x_texture;
		extern sf::Texture o_texture;
		extern sf::Texture e_texture;
};

#endif
