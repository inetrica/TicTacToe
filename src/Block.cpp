#include "Block.h"
#include <iostream>

Block::Block(){
    value = Opt_E;
}

void Block::setVal(blockOption val){
    value = val;
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
