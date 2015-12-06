#include "Block.h"
#include <stdio.h>

Block::Block(){
    value = Opt_E;
}

void Block::setBlock(blockOption val){
    value = val;
}

blockOption Block::Block(){
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
