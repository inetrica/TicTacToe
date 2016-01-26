#include "Block.h"
#include <iostream>

Block::
Block(){
	setVal(Opt_E);
}

Block::
~Block(){

}


int const Block::
getXpos() const {
	return xpos;
}

int const Block::
getYpos() const {
	return ypos;
}

sf::Sprite Block::
getSprite(){
	return sprite;
}

Block::blockOption Block::
getVal() {
    return value;
}

void Block::
setPos(const int x, const int y){
	sprite.setPosition(x, y);
}

void Block::
setVal(const blockOption val){
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

char const Block::
blockToChar() const {
    return blockOptionToChar(value);
}

char Block::
blockOptionToChar(const blockOption opt) {
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
