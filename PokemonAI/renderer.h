#pragma once
#include "pokemonSeed.h"
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

#undef main

class Renderer {
private:
public:
	Renderer();

	void List(vector<pokemonSeed> vector);
};
