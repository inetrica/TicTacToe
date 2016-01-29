#ifndef STATEEVALUATOR_H
#define STATEEVALUATOR_H

#include "Board.h"

class StateEvaluator{
	public:

		StateEvaluator();
		StateEvaluator(const Board ** board);
		StateEvaluator(Block::blockOption ** state, int move, const int sz);
		~StateEvaluator();

		int getLastMove() const;
		Block::blockOption ** getStateArray() const;

	private:
		Block::blockOption **_state;
		int lastMove;
		int size;
}

#endif
