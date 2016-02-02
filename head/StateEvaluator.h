#ifndef STATEEVALUATOR_H
#define STATEEVALUATOR_H

#include "Board.h"

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>

#define MAX_ALPHA 3
#define MIN_BETA -3

class StateEvaluator{
	public:

		StateEvaluator();
		/*
		 * create a state from a Board object
		 * to be used in Player ai makeMove function
		 */
		StateEvaluator(const Board * board);
		/*
		 * create subsequent states based on previous state & move made
		 * sz == width of board
		 */
		//StateEvaluator(Block::blockOption ** state, int move, const int sz);
		~StateEvaluator();

		/*
		 * get the previous made move for this state
		 */
		int getBestMove() const;
		//Block::blockOption ** getStateArray() const;

		/*
		 * return the best move for the player using <playerMark> on the
		 * board, while calculating at most <depth> # of moves ahead
		 */
		void calcBestMove(const Block::blockOption playerMark, int depth);

	private:
		Block::blockOption ** init_state;
		//int lastMove;
		int bestMove;
		int size;

		int heuristic[4];
		void setupHeuristic();

		Block::blockOption ** createState(Block::blockOption ** state, Block::blockOption mark, int move);
		Block::blockOption switchMark(Block::blockOption);

		int max_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth);
		int min_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth);




		/*
		 * get Potential moves to be made from this state
		 */
		std::vector<int> getChildren(Block::blockOption ** _state);

		int evaluate(Block::blockOption ** state, Block::blockOption mark);

		int evaluateRow(Block::blockOption ** state, const int row, const Block::blockOption mark);
		int evaluateCol(Block::blockOption ** state, const int col, const Block::blockOption mark);
		int evaluateLeftDiag(Block::blockOption ** state, const Block::blockOption mark);
		int evaluateRightDiag(Block::blockOption ** state, const Block::blockOption mark);
};

#endif
