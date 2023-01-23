#include "pokemonSeed.h"
#include "battle.h"

using namespace std;

pokemonSeed::pokemonSeed() {
	this->moveList = 0;
	this->pokemon = 0;
	this->moves = new PokemonMove*[4];
	moves[0] = 0;
	moves[1] = 0;
	moves[2] = 0;
	moves[3] = 0;
}
pokemonSeed::pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveNum) {
	this->moveList = moveList;
	pokemon = pokeList->pokemonAtID(pokemonID);
	this->moves = new PokemonMove * [4];
	moves[0] = moveList->FindID(moveID);
	moves[1] = 0;
	moves[2] = 0;
	moves[3] = 0;
	moveIndex[0] = moveNum;
}
/*pokemonSeed::pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveID2) {
	this->moveList = moveList;
	pokemon = pokeList->pokemonAtID(pokemonID);
	this->moves = new PokemonMove * [4];
	moves[0] = moveList->FindID(moveID);
	moves[1] = moveList->FindID(moveID2);
	moves[2] = 0;
	moves[3] = 0;
}*/
pokemonSeed::pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveNum, int win, int draw, int lose) {
	this->moveList = moveList;
	pokemon = pokeList->pokemonAtID(pokemonID);
	this->moves = new PokemonMove * [4];
	moves[0] = moveList->FindID(moveID);
	moves[1] = 0;
	moves[2] = 0;
	moves[3] = 0;
	this->win = win;
	this->draw = draw;
	this->lose = lose;
}
/*pokemonSeed::pokemonSeed(Moves* moveList, Pokemons* pokeList, int pokemonID, int moveID, int moveID2, int win, int draw, int lose) {
	this->moveList = moveList;
	pokemon = pokeList->pokemonAtID(pokemonID);
	this->moves = new PokemonMove * [4];
	moves[0] = moveList->FindID(moveID);
	moves[1] = moveList->FindID(moveID2);
	moves[2] = 0;
	moves[3] = 0;
	this->win = win;
	this->draw = draw;
	this->lose = lose;
}*/

PokemonMove* pokemonSeed::GetMove(int id) {
	if (id < 1) {
		return moves[-id];
	}
	return moveList->FindID(id);
}
Pokemon* pokemonSeed::GetPoke() {
	return pokemon;
}
int pokemonSeed::GetAction(Battle* battleData, int selfID) {
	if (battleData->getPP(selfID, 0) > 0)
		return 1;
	else
		return 0;
}
int pokemonSeed::GetWin() {
	return win;
}
int pokemonSeed::GetDraw() {
	return draw;
}
int pokemonSeed::GetLose() {
	return lose;
}
int pokemonSeed::GetPower() {
	return evoStrength;
}
int pokemonSeed::GetMoveIndex(int n) {
	return moveIndex[n];
}

void pokemonSeed::AddWin() {
	win++;
}
void pokemonSeed::AddDraw() {
	draw++;
}
void pokemonSeed::AddLose() {
	lose++;
}
void pokemonSeed::AddPower() {
	evoStrength++;
}
void pokemonSeed::SubtractPower() {
	evoStrength--;
}

void pokemonSeed::ClearWDL() {
	win = 0;
	draw = 0;
	lose = 0;
}

void pokemonSeed::PrintSeed() {
	cout << pokemon->getName() << "," << moves[0]->getName() << " : " << evoStrength;
	if (moves[1])
		cout << "," << moves[1]->getName();
	cout << endl;
	cout << "W:" << win << " D:" << draw << " L:" << lose << endl;
}

void pokemonSeed::PrintSeedFile(fstream* filestream) {
	*filestream << pokemon->getName() << "," << moves[0]->getName() << endl;
	*filestream << "W:" << win << " D:" << draw << " L:" << lose << endl;
}