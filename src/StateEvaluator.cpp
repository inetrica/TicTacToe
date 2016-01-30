#include "StateEvaluator.h"

StateEvaluator::
StateEvaluator(){
	 size = 3;
	init_state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		init_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			init_state[i][j] = Block::Opt_E;
		}
	}
	bestMove = -1;
}

StateEvaluator::
StateEvaluator(const Board * board){
	size = board->getSize();
	init_state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		init_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			init_state[i][j] = board->getBlockValueAt(i, j);
		}
	}
	bestMove = -1;
}

/*
StateEvaluator::
StateEvaluator(Block::blockOption ** state, int move, Block::blockOption mark, const int sz){
	size = sz;
	init_state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		init_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			init_state[i][j] = state[i][j];
		}
	}
	int row = move/size;
	int col = move%size;
	_state[row][col] = mark;
	bestMove = -1;
}
*/

StateEvaluator::
~StateEvaluator(){
	for(int i = 0; i < size; i++){
		delete[] init_state[i];
	}

	delete[] init_state;
}

int StateEvaluator::
getBestMove() const{
	return bestMove;
}

void StateEvaluator::
calcBestMove(const Block::blockOption playerMark, int depth){
	max_value(init_state, switchMark(playerMark), depth);
}

Block::blockOption ** StateEvaluator::
createState(Block::blockOption ** state, Block::blockOption mark, int move){
	Block::blockOption ** _state = new Block::blockOption*[size];
	for(int i = 0; i < size; i++){
		_state[i] = new Block::blockOption[size];
		for(int j = 0; j < size; j++){
			_state[i][j] = state[i][j];
		}
	}
	int row = move/size;
	int col = move%size;
	_state[row][col] = mark;
	return _state;

}

Block::blockOption StateEvaluator::
switchMark(Block::blockOption mark){
	if(mark == Block::Opt_X) return Block::Opt_O;
	else return Block::Opt_X;
}

int StateEvaluator::
max_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth){
	std::vector<int> children = getChildren(state);
	/*
	 * no more possible moves, then return -1
	 */
	if(children.size() == 0){
		bestMove = -1;
		return MIN_BETA;
	} else if (depth == 0){
		/*
		 * evaluate at the current state based on heuristic
		 */
		bestMove = -1;
		return evaluate(state, playerMark);
	} else {
		//initiate alpha to be ridiculously low
		int alpha = -1000;

		for(unsigned i = 0; i < children.size(); i++){
			/*
			 * create next state
			 */
			Block::blockOption nextMark = switchMark(playerMark);
			int childValue = min_value(createState(state, nextMark, children[i]), nextMark, depth - 1);
			if(childValue > alpha){
				alpha = childValue;
				bestMove = children[i];
			}

			if(alpha >= MAX_ALPHA){
				break;
			}
		}
		return alpha;
	}
}

int StateEvaluator::
min_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth){
	std::vector<int> children = getChildren(state);
	/*
	 * no more possible moves, then return -1
	 */
	if(children.size() == 0){
		bestMove = -1;
		return MAX_ALPHA;
	} else if (depth == 0){
		/*
		 * evaluate at the current state based on heuristic
		 */
		bestMove = -1;
		return evaluate(state, playerMark);
	} else {
		//initiate alpha to be ridiculously low
		int beta = 1000;

		for(unsigned i = 0; i < children.size(); i++){
			/*
			 * create next state
			 */
			Block::blockOption nextMark = switchMark(playerMark);
			int childValue = max_value(createState(state, nextMark, children[i]), nextMark, depth - 1);
			if(childValue < beta){
				beta = childValue;
				bestMove = children[i];
			}

			if(beta <= MIN_BETA){
				break;
			}
		}
		return beta;
	}
}

std::vector<int> StateEvaluator::
getChildren(Block::blockOption ** _state){
	std::vector<int> children;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(_state[i][j] == Block::Opt_E){
				children.push_back(i*3 + j);
			}
		}
	}
	return children;
}

int StateEvaluator::
evaluate(Block::blockOption ** state, Block::blockOption mark){
	int options = 0;
	options += countRows(state, mark);
	options += countCols(state, mark);
	options += countDiags(state, mark);
	return options;
}

int StateEvaluator::
countRows(Block::blockOption ** state, Block::blockOption mark){
	int rows = size;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j ++){
			if(state[i][j] != mark && state[i][j] != Block::Opt_E){
				rows--;
				break;
			}
		}
	}
	return rows;
}

int StateEvaluator::
countCols(Block::blockOption ** state, Block::blockOption mark){
	int cols = size;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j ++){
			if(state[j][i] != mark && state[j][i] != Block::Opt_E){
				cols--;
				break;
			}
		}
	}
	return cols;
}

int StateEvaluator::
countDiags(Block::blockOption ** state, Block::blockOption mark){
	int diag = 2;
	for(int i = 0; i < size; i++){
		if(state[i][i] != mark && state[i][i] != Block::Opt_E){
			diag--;
			break;
		}
	}

	int i = 0;
	int j = size - 1;
	for(; i < size && j >= 0; i++, j--){
		if(state[i][j] != mark && state[i][j] != Block::Opt_E){
			diag--;
			break;
		}
	}
	return diag;
}

