#include "Player.h"
#include "TestBase.h"

void
testConstructor(){
	Player p1(Block::Opt_X, false);
	assert("P1 has Mark X, Is not AI", p1.getMark() == Block::Opt_X
			&& !p1.isAI());


}

int
main(){


	return 0;
}
