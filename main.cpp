#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	game = new Game();
	game->init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	while (game->getIsRunning()) {
		game->input();
		game->update();
		game->render();
	}
	game->quit();
	delete game;
	return 0;
}