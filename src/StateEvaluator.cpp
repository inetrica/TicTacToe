#include "StateEvaluator.h"

StateEvaluator::
StateEvaluator(){
	 size = 3;
	_state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			_state[i][j] = Block::Opt_E;
		}
	}
	lastMove = -1;
}

StateEvaluator::
StateEvaluator(const Board * board){
	size = board.getSize();
	_state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			_state[i][j] = board.getBlockValueAt(i, j);
		}
	}
	lastMove = -1;
}

StateEvaluator::
StateEvaluator(Block::blockOption ** state, int move, const int sz){
	size = sz;
	_state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			_state[i][j] = state[i][j];
		}
	}
	lastMove = move;
}

StateEvaluator::
~StateEvaluator(){
	for(int i = 0; i < size; i++){
		delete[] _state[i];
	}

	delete[] _state;
}

int StateEvaluator::
getLastMove() const{
	return lastMove;
}

Block::blockOption ** StateEvaluator::
getStateArray() const{
	return _state;
}

