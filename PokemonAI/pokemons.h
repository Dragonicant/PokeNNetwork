#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "pokemon.h"
#include "moves.h"

class Pokemons {
private:
	vector<Pokemon> pokemons;

	Moves* moveList;

public:
	Pokemons(string speciesFile, string statsFile, string movesFile, string typeFile, Moves* moves);

	Pokemon* pokemonAtID(int id);
	bool hasPokemonAtID(int id);

	int numPokes();

	void FindByType(int type);
	void FindByID(int id);

	void Disable(int id);
	void Enable(int id);
};
