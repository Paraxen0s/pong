#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Game
{
public:
	void init(const char* name, int xPos, int yPos, int xSize, int ySize);
	void input();
	void render();
	void update();
	void quit();

	bool getIsRunning();
	double getDeltaTime();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning = false;

	Uint64 lastFrame = 0;
	Uint64 thisFrame = SDL_GetPerformanceCounter();
	double deltaTime = 0;
	double frameTimer = 0;
};
