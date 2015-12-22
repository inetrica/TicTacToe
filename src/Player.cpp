#include "Player.h"

Player::Player(){
	playerMark = Block::Opt_X;
	ai = false;
}

Player::Player(Block::blockOption mark, bool ai){
	playerMark = mark;
	this->ai = ai;
}

Player::~Player(){

}

Block::blockOption Player::getMark(){
	return playerMark;
}

bool Player::isAI(){
	return ai;
}
