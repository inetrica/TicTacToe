#include "Block.h"

Block::Block(){
    value = Opt_E;
}

void Block::setBlock(blockOption val){
    value = val;
}

blockOption Block::Block(){
    return value;
}
