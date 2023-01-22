#include "moves.h"
#include "pokemons.h"
#include "seeds.h"
#include "renderer.h"

using namespace std;

//using data from https://github.com/veekun/pokedex/tree/master/pokedex/data/csv
//icons from https://veekun.com/dex/downloads
//full images from https://www.kaggle.com/datasets/arenagrenade/the-complete-pokemon-images-data-set?resource=download

void convertFile(string originalFile, string newFile, vector<int> excluded, int genLimit) {
	fstream fin, fout;

	fin.open(originalFile, ios::in);
	fout.open(newFile, ios::out);

	string temp, line, word;
	vector<string> row;

	bool include;
	bool generationed = false;
	int generationIndex = -1;

	row.clear();

	getline(fin, line);
	stringstream ss(line);

	while (getline(ss, word, ',')) {
		if (word == "") {
			word = "-1";
		}
		row.push_back(word);
	}

	for (int i = 0; i < row.size(); i++) {
		if (row[i] == "generation_id" || row[i] == "version_group_id") {
			generationIndex = i;
		}
	}

	for (int i = 0; i < row.size(); i++) {
		include = true;
		for (int j = 0; j < excluded.size(); j++) {
			if (i == excluded.at(j)) {
				include = false;
			}
		}
		if (include) {
			if (i != 0) {
				fout << ",";
			}
			fout << row.at(i);
		}
	}
	fout << endl;

	while (!fin.eof()) {
		row.clear();

		getline(fin, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			if (word == "") {
				word = "-1";
			}
			row.push_back(word);
		}

		int rowCheck = 99;
		if (generationIndex != -1){
			rowCheck = stoi(row[generationIndex]);
		}
		if (rowCheck <= genLimit || rowCheck == 99) {
			for (int i = 0; i < row.size(); i++) {
				include = true;
					for (int j = 0; j < excluded.size(); j++) {
						if (i == excluded.at(j)) {
							include = false;
						}
					}

					if (include) {
						if (i != 0) {
							fout << ",";
						}
						fout << row.at(i);
					}
				}
			fout << endl;
		}
	}
	fin.close();
	fout.close();
}

int main() {

	bool reloadFiles = false;
	int genLimit = 1;

	if (reloadFiles) {
		vector<int> tempVector = { 2, 8, 12, 13, 14 };
		convertFile("csv/moves.csv", "create/moves.csv", tempVector, genLimit);

		tempVector = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
		convertFile("csv/pokemon_species.csv", "create/pokemonSpecies.csv", tempVector, genLimit);

		tempVector = { 3 };
		convertFile("csv/pokemon_stats.csv", "create/pokemonStats.csv", tempVector, genLimit);

		tempVector = { 1, 3, 4, 5 };
		convertFile("csv/pokemon_moves.csv", "create/pokemonMoves.csv", tempVector, genLimit);


		tempVector = {};
		convertFile("csv/pokemon_types.csv", "create/pokemonTypes.csv", tempVector, genLimit);

		tempVector = {};
		convertFile("csv/move_meta.csv", "create/moveMeta.csv", tempVector, genLimit);
	}

	Moves moveList("create/moves.csv", "create/moveMeta.csv");

	Pokemons pokeList("create/pokemonSpecies.csv", "create/pokemonStats.csv", "create/pokemonMoves.csv", "create/pokemonTypes.csv", &moveList);

	//for (int i = 7; i < 151 + 1; i++)
	//	pokeList.Disable(i);

	pokeList.Disable(150);//mewtwo
	pokeList.Disable(151);//mew

	moveList.Disable(165);//struggle; we disable struggle so it doesnt show up in evo data, this shouldnt break anything else



	int generations = 1000;
	bool load = false;
	bool battleOutput = false;
	bool WLOutput = false;
	int bestOfNum = 3;
	int moves = 1;
	bool output = true;

	seeds seedList(&pokeList, &moveList, load, battleOutput, WLOutput, bestOfNum, moves, output);

	for(int i = 0; i < generations; i++){
		seedList.generate();
	}

	if(output)
		seedList.showStrongest();

	Renderer renderer;

	renderer.List(seedList.getStrongest());
	renderer.ListLong(seedList.getStrongest());
	renderer.ListExtinction(&pokeList, generations);
}