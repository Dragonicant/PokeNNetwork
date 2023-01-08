#pragma once
#include "pokemonSeed.h"
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

#undef main

class Renderer {
private:
	int screenWidth;
	int screenHeight;

	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Renderer();
	~Renderer();

	void List(vector<pokemonSeed> vector);
};
