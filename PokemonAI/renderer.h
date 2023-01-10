#pragma once
#include "pokemonSeed.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <vector>

#undef main

class Renderer {
private:
	int screenWidth;
	int screenHeight;

public:
	Renderer();
	~Renderer();

	void List(vector<pokemonSeed> vector);
	void ListLong(vector<pokemonSeed> vector);
	void ListExtinction(Pokemons* list, int generations);
};
