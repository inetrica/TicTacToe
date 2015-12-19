#ifndef GAME_H
#define GAME_H

class Game{
	public:
		Game();
		~Game();

		void loadTextures();

	private:
		Board board;
};

#endif
