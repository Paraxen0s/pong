#include "Game.h"
#include "Paddle.h"

void Game::init(const char* name, int xPos, int yPos, int xSize, int ySize)
{
	std::cout << "SDL2 Initializing..." << std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Window Initializing..." << std::endl;
		window = SDL_CreateWindow(name, xPos, yPos, xSize, ySize, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		std::cout << "Renderer Initializing..." << std::endl;
		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
	}
}

void Game::input()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	lastFrame = thisFrame;
	thisFrame = SDL_GetPerformanceCounter();
	deltaTime = (double)((thisFrame - lastFrame) * 1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;
	frameTimer += deltaTime;

	if (frameTimer > (1.0 / 60.0)) {
		/**/
		frameTimer = 0;
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 20, 160, 180, 255);
	SDL_RenderClear(renderer);

	/**/

	SDL_RenderPresent(renderer);
}

void Game::quit()
{
	std::cout << "Game Quitting..." << std::endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game Quit" << std::endl;
}

bool Game::getIsRunning()
{
	return isRunning;
}

double Game::getDeltaTime()
{
	return deltaTime;
}