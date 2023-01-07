#include "pokemons.h"

using namespace std;

Pokemons::Pokemons(string speciesFile, string statsFile, string movesFile, string typeFile, Moves* moves) {
	fstream fspecies, fstats, fmoves, ftypes;

	fspecies.open(speciesFile, ios::in);
	fstats.open(statsFile, ios::in);
	fmoves.open(movesFile, ios::in);
	ftypes.open(typeFile, ios::in);

	string temp, line, word;
	vector<string> row;

	getline(fspecies, line);
	while (!fspecies.eof()) {
		row.clear();

		getline(fspecies, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			row.push_back(word);
		}

		Pokemon temp;

		temp.setID(stoi(row[0]));
		temp.setName(row[1]);

		pokemons.push_back(temp);
	}

	getline(fstats, line);
	while (!fstats.eof()) {
		row.clear();

		getline(fstats, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			row.push_back(word);
		}

		if (hasPokemonAtID(stoi(row[0]))) {
			Pokemon* temp = pokemonAtID(stoi(row[0]));

			switch (stoi(row[1])) {
			case 1:
				temp->setHP(stoi(row[2]));
			case 2:
				temp->setATK(stoi(row[2]));
			case 3:
				temp->setDEF(stoi(row[2]));
			case 4:
				temp->setSPA(stoi(row[2]));
			case 5:
				temp->setSPD(stoi(row[2]));
			case 6:
				temp->setSPE(stoi(row[2]));
			};
		}
	}

	getline(ftypes, line);
	while (!ftypes.eof()) {
		row.clear();

		getline(ftypes, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			row.push_back(word);
		}

		if (hasPokemonAtID(stoi(row[0]))) {
			Pokemon* temp = pokemonAtID(stoi(row[0]));

			if (row[2] == "1") {
				temp->setType(stoi(row[1]));
			}
			if (row[2] == "2") {
				temp->setType2(stoi(row[1]));
			}
		}
		
	}

	getline(fmoves, line);
	while (!fmoves.eof()) {
		row.clear();

		getline(fmoves, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			row.push_back(word);
		}

		if (hasPokemonAtID(stoi(row[0]))) {
			Pokemon* temp = pokemonAtID(stoi(row[0]));
			if (!temp->hasMove(stoi(row[1]))) {
				temp->addMove(stoi(row[1]));
			}
		}
	}

	moveList = moves;
}

Pokemon* Pokemons::pokemonAtID(int id) {
	return &pokemons.at(id-1);
}

bool Pokemons::hasPokemonAtID(int id) {
	if (id > pokemons.size()) {
		return false;
	}
	return true;
}

int Pokemons::numPokes() {
	return int(pokemons.size());
}

void Pokemons::FindByType(int type) {
	for (auto& element : pokemons) {
		if (element.getType() == type || element.getType2() == type) {
			element.printPokemon(moveList);
			cout << endl;
		}
	}
}

void Pokemons::FindByID(int id) {
	pokemons.at(id - 1).printPokemon(moveList);
}

void Pokemons::Disable(int id) {
	pokemons.at(id - 1).Disable();
}

void Pokemons::Enable(int id) {
	pokemons.at(id - 1).Enable();
}