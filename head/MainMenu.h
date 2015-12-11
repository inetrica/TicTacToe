#ifndef MAINMENU_H
#define MAINMENU_H

class MainMenu {
	public:
		MainMenu();

		enum gamemode{
			SinglePlayer,
			TwoPlayer
		};

		enum difficulty{
			Easy,
			Medium
		};

		gamemode getGamemode();
		difficulty getDifficulty();

		void runMainMenu();

	private:
		bool active;
		gamemode _gamemode;
		difficulty _difficulty;

};

#endif
