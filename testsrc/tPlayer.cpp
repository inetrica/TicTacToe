#include "Player.h"
#include "TestBase.h"
#include <stdio.h>

void
testConstructor(){
	Player p1(Block::Opt_X, false);
	assert("P1 has Mark X, Is not AI", p1.getMark() == Block::Opt_X
			&& !p1.isAI());

	Player p2(Block::Opt_O, true);
	assert("P2 has Mark O, is AI", p2.getMark() == Block::Opt_O
			&& p2.isAI());
}

/*
 * test makeMove() for easy AI
 */
void
testAiEasy(){
	GameState gs; //default constructor = Easy, SinglePlayer
	Player ai(Block::Opt_X, true);

	//To test makeMove(), need sf::RenderWindow
	int win_sz = BLOCK_PIXEL_SZ*gs.getBoard()->getSize();
	sf::RenderWindow window(sf::VideoMode(win_sz, win_sz), "Player Test Window");

	//Fill whole board, should fill in random order, but be full after 9x
	for(int i = 9; i > 0; i--){
		//http://stackoverflow.com/questions/10410023/string-format-alternative-in-c
		//Creating test name
		std::string s = "Number of Empty slots: ";
		char * c =  new char[s.length() + 32];
		sprintf(c, "%s%d", s.c_str(), i);
		std::string testName = c;
		delete c;

		assert(testName, gs.getBoard()->getNumEmptySlots() == i);
		ai.makeMove(window, &gs);
		sf::sleep(sf::milliseconds(300));
	}

	assert("Board Full", gs.getBoard()->getNumEmptySlots() == 0);
	
	sf::sleep(sf::milliseconds(500));
	window.close();
	
}

int
main(){
	testConstructor();

	testAiEasy();

	return 0;
}
