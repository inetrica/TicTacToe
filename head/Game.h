#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game{
	public:

		enum gamemode{
			SinglePlayer,
			TwoPlayer
		};

		enum difficulty{
			Easy,
			Medium
		};

		Game();
		Game(gamemode mode, difficulty diff);
		~Game();

		int Game::checkWinCondition(const Board & board);

		void easySingle(sf::RenderWindow & window);

		void hardSingle(sf::RenderWindow & window);

		void pvp(sf::RenderWindow & window);

		void loop();

	private:
		gamemode _gamemode;
		difficulty _difficulty;
};

#endif
