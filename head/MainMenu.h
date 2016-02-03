#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"

class MainMenu {
	public:
		MainMenu();
		~MainMenu();

		GameState * getGameState() const;

		void runLoop();

	private:
		GameState * gs;
};

#endif
