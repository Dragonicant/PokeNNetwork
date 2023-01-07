#pragma once

#include "pokemons.h"
#include "pokemonHelper.h"

class pokemonSeed;

class Battle {
private:
	pokemonSeed* pokemon[2];

	Pokemon* stats[2];

	PokemonMove* moves[2][4];
	PokemonMove* chosenMove[2];

	bool battleOutput;
	int attacker;

	int turnNum;
	int turnsCharging[2];
	int flying[2];
	int flinched[2];
	int nvStatus[2];
	int turnsToxic[2];
	int turnsAsleep[2];
	int turnsSlept[2];
	int trapped[2];
	int turnsTrapped[2];
	int turnsTrappedFor[2];

	int lockedMove[2];
	int movePP[2][4];
	int currentHP[2];

	int hp[2];
	int atk[2];
	int def[2];
	int spa[2];
	int spd[2];
	int spe[2];

	int hpStage[2];
	int atkStage[2];
	int defStage[2];
	int spaStage[2];
	int spdStage[2];
	int speStage[2];
	int accStage[2];
	int evaStage[2];

	int result;

public:
	Battle(pokemonSeed* pokemonA, pokemonSeed* pokemonB, bool battleOutput);

	void Calculate();
	void Turn();
	void Move();
	void ChooseMove();

	bool hits();
	int Speed();

	int currentatk(int attacker);
	int currentdef(int attacker);
	int currentspa(int attacker);
	int currentspd(int attacker);
	int currentspe(int attacker);

	int getResult();

	int getPP(int selfID, int index);
};