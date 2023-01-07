#pragma once
#include <fstream>
#include <sstream>
#include "move.h"

class Moves {
private:
	vector<PokemonMove> moves;

public:
	Moves(string fileName, string moveMetaName);

	vector<PokemonMove> getVector();

	void Print();
	void FindByType(int type);
	
	PokemonMove* FindID(int id);

	void Disable(int id);
};