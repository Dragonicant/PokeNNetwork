#include "moves.h"

Moves::Moves(string fileName, string moveMetaName) {
	fstream fin, fmeta, WIP;

	vector<int> finishedMoves = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 18, 19, 20, 24, 28, 30, 32, 33, 34, 35, 38, 39, 40, 41, 42, 43, 44, 45, 46, 49, 51, 52, 53, 55, 60, 61, 67, 68, 71, 73, 76, 81, 84, 88, 104, 146, 150, 152, 153, 156, 157, 199, 255, 317};

	fin.open(fileName, ios::in);
	fmeta.open(moveMetaName, ios::in);
	WIP.open("create/movesInProgress.csv", ios::out);

	string temp, line, word;
	vector<string> row;

	getline(fin, line);
	while (!fin.eof()) {
		row.clear();

		getline(fin, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			row.push_back(word);
		}

		PokemonMove temp;

		temp.setID(stoi(row[0]));
		temp.setName(row[1]);
		temp.setType(stoi(row[2]));
		temp.setPower(stoi(row[3]));
		temp.setPP(stoi(row[4]));
		temp.setAccuracy(stoi(row[5]));
		temp.setPriority(stoi(row[6]));
		temp.setDamageClass(stoi(row[7]));
		temp.setEffectID(stoi(row[8]));
		temp.setEffectChance(stoi(row[9]));

		bool finished = false;
		for (int i = 0; i < finishedMoves.size(); i++) {
			if(stoi(row[8]) == finishedMoves.at(i))
				finished = true;
		}
		if (!finished) {
			for (int i = 0; i < 9; i++) {
				WIP << row[i] << ",";
			}
			WIP << row[9] << endl;
		}
			

		moves.push_back(temp);
	}

	getline(fmeta, line);
	while (!fmeta.eof()) {
		row.clear();

		getline(fmeta, line);
		stringstream ss(line);

		if (line == "") {
			break;
		}

		while (getline(ss, word, ',')) {
			row.push_back(word);
		}
		if (stoi(row[0]) < moves.size()) {
			PokemonMove* temp = FindID(stoi(row[0]));

			temp->setMetaID(stoi(row[1]));
		}
	}
	fin.close();
	fmeta.close();
	WIP.close();
}

vector<PokemonMove> Moves::getVector() {
	return moves;
}

void Moves::Print() {
	for (auto& element : moves) {
		cout << endl;
		element.printMove();
	}
}

void Moves::FindByType(int type) {
	for (auto& element : moves) {
		if (element.getType() == type) {
			cout << endl;
			element.printMove();
		}
	}
}

PokemonMove* Moves::FindID(int id) {
	if (id > moves.size()) {
		cout << "ERROR: FindID asked to find out of range move" << endl;
		return &moves.at(0);
	}
	return &moves.at(id - 1);
}

void Moves::Disable(int id) {
	moves.at(id - 1).setDisabled();
}