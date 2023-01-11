#pragma once
#include <queue>
#include "pokemonSeed.h"
#include "pokemonHelper.h"
#include "battle.h"

class seeds {
private:
	vector<pokemonSeed> seedList;

	Pokemons* pokeList;
	Moves* moveList;

	vector<pokemonSeed> strongest;

	int battleOutput;
	int WLOutput;
	int output;

	int bestOfNum;

	int generation = 1;

	fstream seedSave;

public:
	seeds(Pokemons* pokeList, Moves* moveList, bool load, bool battleOutput, bool WLOutput, int bestOfNum, int moves, int output);
	~seeds();

	void simulate();
	void generate();
	void Extinct();

	void battle(pokemonSeed* pokeA, pokemonSeed* pokeB);
	void top100();
	void showStrongest();
	void listID(int id);

	int GetSize();
	vector<pokemonSeed> getStrongest();
};