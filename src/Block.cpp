#include "Block.h"
#include <iostream>

Block::
Block(){
	setVal(Opt_E);
}

Block::
~Block(){

}


int Block::
getXpos(){
	return xpos;
}

int Block::
getYpos(){
	return ypos;
}

sf::Sprite Block::
getSprite(){
	return sprite;
}

Block::blockOption Block::
getVal(){
    return value;
}

void Block::
setPos(int x, int y){
	sprite.setPosition(x, y);
}

void Block::
setVal(blockOption val){
    value = val;
    switch(val){
    	case Opt_E:
    		sprite.setTexture(textures::e_texture);
    		break;
		case Opt_X:
			sprite.setTexture(textures::x_texture);
			break;
		case Opt_O:
			sprite.setTexture(textures::o_texture);
			break;
		default:
			exit(-2);
    }
}

char Block::
blockToChar(){
    return blockOptionToChar(value);
}

char Block::
blockOptionToChar(blockOption opt){
	switch(opt){
        case Opt_E:
            return ' ';
        case Opt_X:
            return 'X';
        case Opt_O:
            return 'O';
        default:
            std::cerr << "Invalid Block Option set" << std::endl;
            return '?';
    }
}
