#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include "Textures.h"

#define BLOCK_SZ 70

class Block
{
    
    public:

        enum blockOption
        {
            Opt_X, //X
            Opt_O, //O
            Opt_E  //Empty
        };

        Block();

        ~Block();

        int getXpos();

        int getYpos();

        void setPos(int x, int y);

        void setVal(blockOption val);

        blockOption getVal();

        char blockToChar();

        static char blockOptionToChar(blockOption opt);
		
		sf::Sprite getSprite();

    private:
        blockOption value;
		sf::Sprite sprite;
		int xpos, ypos;

};

#endif
