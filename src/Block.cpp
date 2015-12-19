#include "Block.h"
#include <iostream>

Block::Block(){
	setVal(Opt_E);
}

Block::~Block(){

}


int Block::getXpos(){
	return xpos;
}

int Block::getYpos(){
	return ypos;
}

void Block::setPos(int x, int y){
	sprite.setPosition(x, y);
}

void Block::setVal(blockOption val){
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

Block::blockOption Block::getVal(){
    return value;
}

char Block::blockToChar(){
    switch(value){
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

sf::Sprite Block::getSprite(){
	return sprite;
}
