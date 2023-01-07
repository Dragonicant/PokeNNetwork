#pragma once
#include "pokemonSeed.h"
#include <string>
#include <vector>
#include "moves.h"


string convertType(int type);
string convertMove(int moveID, Moves* moveList);
float typeEffectiveness(int attackingType, int defendingType, int defendingType2);

int partition(std::vector<pokemonSeed> &arr, int low, int high);
void quickSort(std::vector<pokemonSeed> &arr, int low, int high);