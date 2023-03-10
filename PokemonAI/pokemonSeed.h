#pragma once

#include "pokemons.h"

class Battle;

class pokemonSeed {
private:
	Moves* moveList;
	int moveIndex[4];

	Pokemon* pokemon;
	PokemonMove** moves;

	int win = 0;
	int draw = 0;
	int lose = 0;

	int evoStrength = 1;

public:
	pokemonSeed();
	pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveNum);
	//pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveID2);
	pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveNum, int win, int draw, int lose);
	//pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveID2, int win, int draw, int lose);

	PokemonMove* GetMove(int id);
	Pokemon* GetPoke();
	int GetAction(Battle* battleData, int selfID);
	int GetWin();
	int GetDraw();
	int GetLose();
	int GetPower();
	int GetMoveIndex(int n);

	void AddWin();
	void AddDraw();
	void AddLose();
	void AddPower();
	void SubtractPower();

	void ClearWDL();

	void PrintSeed();
	void PrintSeedFile(fstream* filestream);
};