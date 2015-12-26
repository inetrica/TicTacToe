#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include "Textures.h"

//Block size in pixels
#define BLOCK_SZ 70

class Block
{
    
    public:

		//Valid values for a block, typical
		//tic tac toe game, one player places
		//X's, other places O's, E represents Empty
        enum blockOption
        {
            Opt_X, //X
            Opt_O, //O
            Opt_E  //Empty
        };

        Block();

        ~Block();

		//X and Y positions for the sprite
        int getXpos();
        int getYpos();
        void setPos(int x, int y);

		//set the value to X or O (or Empty)
        void setVal(blockOption val);
        blockOption getVal();

		//Convert the value of this block to a character
        char blockToChar();

        //Convert the passed argument (blockOption) to a character
        static char blockOptionToChar(blockOption opt);
		
		/*
		 * get the SFML sprite for this block
		 */
		sf::Sprite getSprite();

    private:
        blockOption value;
		sf::Sprite sprite;
		int xpos, ypos;

};

#endif
