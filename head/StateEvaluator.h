#ifndef STATEEVALUATOR_H
#define STATEEVALUATOR_H

#include "Board.h"

#define MAX_ALPHA 8
#define MIN_BETA -8

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

		Block::blockOption ** createState(Block::blockOption ** state, Block::blockOption mark, int move);
		Block::blockOption switchMark(Block::blockOption);

		int max_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth);
		int min_value(Block::blockOption ** state, const Block::blockOption playerMark, int depth);




		/*
		 * get Potential moves to be made from this state
		 */
		std::vector<int> getChildren(Block::blockOption ** _state);

		int evaluate(Block::blockOption ** state, Block::blockOption mark);

		int countRows(Block::blockOption ** state, Block::blockOption mark);
		int countCols(Block::blockOption ** state, Block::blockOption mark);
		int countDiags(Block::blockOption ** state, Block::blockOption mark);
};

#endif
