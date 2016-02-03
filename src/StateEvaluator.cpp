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
	setupHeuristic();
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
	setupHeuristic();
}

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

void StateEvaluator::
setupHeuristic(){
	heuristic[0] = 0;
	heuristic[1] = 10;
	heuristic[2] = 100;
	heuristic[3] = 1000;
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
		//bestMove = -1;
		//return MIN_BETA;
		return -1*evaluate(state, playerMark);//*-1
	} else if (depth == 0){
		/*
		 * evaluate at the current state based on heuristic
		 */
		//bestMove = -1;
		return -1*evaluate(state, playerMark);
	} else {
		//initiate alpha to be ridiculously low
		int alpha = -10000;

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

			/*
			if(alpha >= MAX_ALPHA){
				break;
			}
			*/
		}
		return alpha;
	}
}

int StateEvaluator::
min_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth){
	std::vector<int> children = getChildren(state);
	/*
	 * no more possible moves, then return 1
	 */
	if(children.size() == 0){
		//bestMove = -1;
		//return MAX_ALPHA;
		return evaluate(state, playerMark);
	} else if (depth == 0){
		/*
		 * evaluate at the current state based on heuristic
		 */
		//bestMove = -1;
		return evaluate(state, playerMark);
	} else {
		//initiate alpha to be ridiculously low
		int beta = 10000;

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

			/*
			if(beta <= MIN_BETA){
				break;
			}
			*/
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
	std::srand (unsigned (std::time(0)));
	std::random_shuffle(children.begin(), children.end());
	return children;
}

int StateEvaluator::
evaluate(Block::blockOption ** state, const Block::blockOption mark){
	int sum = 0;
	for(int i = 0; i < size; i++){
		int row = evaluateRow(state, i, mark);
		int col = evaluateCol(state, i, mark);
		sum += row;
		sum += col;
		/*
		if(row == MAX_ALPHA || row == MIN_BETA)
			return row;
		if(col == MAX_ALPHA || col == MIN_BETA)
			return col;
		*/
	}
	int ldiag = evaluateLeftDiag(state, mark);
	int rdiag = evaluateRightDiag(state, mark);
	sum += ldiag;
	sum += rdiag;

	/*
	if(ldiag == MAX_ALPHA || ldiag == MIN_BETA) return ldiag;
	if(rdiag == MAX_ALPHA || rdiag == MIN_BETA) return rdiag;
	*/

	//std::cout << sum << std::endl;
	return sum;
}

int StateEvaluator::
evaluateRow(Block::blockOption ** state, const int row, const Block::blockOption mark){
	int pCount, oCount; //player count, opponent count (# of marks in diag)
	pCount = oCount = 0;

	for(int i = 0; i < size; i++){
		if(state[row][i] == mark) pCount += 1;
		else if(state[row][i] == switchMark(mark)) oCount += 1;
	}
	if(pCount == 0) return -1*heuristic[oCount];
	else if(oCount == 0) return heuristic[pCount];
	else return 0;
}

int StateEvaluator::
evaluateCol(Block::blockOption ** state, const int col, const Block::blockOption mark){
	int pCount, oCount; //player count, opponent count (# of marks in diag)
	pCount = oCount = 0;

	for(int j = 0; j < size; j++){
		if(state[j][col] == mark) pCount += 1;
		else if(state[j][col] == switchMark(mark)) oCount += 1;
	}
	if(pCount == 0) return -1*heuristic[oCount];
	else if(oCount == 0) return heuristic[pCount];
	else return 0;
}

int StateEvaluator::
evaluateLeftDiag(Block::blockOption ** state, const Block::blockOption mark){
	int pCount, oCount; //player count, opponent count (# of marks in diag)
	pCount = oCount = 0;

	for(int i = 0; i < size; i++){
		if(state[i][i] == mark) pCount += 1;
		else if(state[i][i] == switchMark(mark)) oCount += 1;
	}
	if(pCount == 0) return -1*heuristic[oCount];
	else if(oCount == 0) return heuristic[pCount];
	else return 0;
}

int StateEvaluator::
evaluateRightDiag(Block::blockOption ** state, const Block::blockOption mark){
	int i = 0;
	int j = size - 1;
	int pCount, oCount; //player count, opponent count (# of marks in diag)
	pCount = oCount = 0;
	for(; i < size && j >= 0; i++, j--){
		if(state[i][j] == mark) pCount += 1;
		else if(state[i][j] == switchMark(mark)) oCount += 1;
	}

	if(pCount == 0) return -1*heuristic[oCount];
	else if(oCount == 0) return heuristic[pCount];
	else return 0;
}

