#include "seeds.h"

using namespace std;

seeds::seeds(Pokemons* pokeList, Moves* moveList, bool load, bool battleOutput, bool WLOutput, int bestOfNum, int moves, int output) {
	this->battleOutput = battleOutput;
	this->WLOutput = WLOutput;
	this->output = output;

	this->bestOfNum = bestOfNum;

	this->pokeList = pokeList;
	this->moveList = moveList;
	this->maxMoveNum = pokeList->pokemonAtID(1)->getMoves().size();
	for (int i = 2; i <= pokeList->numPokes(); i++) {
		if (!pokeList->pokemonAtID(i)->isDisabled()) {
			if (maxMoveNum < pokeList->pokemonAtID(i)->getMoves().size()) {
				if (output)
					cout << pokeList->pokemonAtID(i)->getName() << " has " << pokeList->pokemonAtID(i)->getMoves().size() << " moves!" << endl;
				maxMoveNum = pokeList->pokemonAtID(i)->getMoves().size();
			}
		}
	}

	seedSave.open("data/seedData.txt", ios::out);

	if (load) {
		fstream seedLoad;

		seedLoad.open("data/seedData.txt", ios::in);

		string temp, line, word;
		vector<string> row;

		while (!seedLoad.eof()) {
			row.clear();

			getline(seedLoad, line);
			stringstream ss(line);

			if (line == "") {
				break;
			}

			while (getline(ss, word, ',')) {
				row.push_back(word);
			}

			seedList.push_back(pokemonSeed(moveList, pokeList, stoi(row[0]), stoi(row[1]), stoi(row[2]), stoi(row[3]), stoi(row[4])));
		}
		std::cout << seedList.size() << " competitors!" << endl;
		return;
	}

	for (int i = 1; i <= pokeList->numPokes(); i++) {
		if (!pokeList->pokemonAtID(i)->isDisabled()) {
			vector<int> temp = pokeList->pokemonAtID(i)->getMoves();
			for (auto& element : temp) {
				if (moves == 2) {
					for (auto& element2 : temp) {
						if (!moveList->FindID(element)->isDisabled() && !moveList->FindID(element2)->isDisabled() && element != element2)
							seedList.push_back(pokemonSeed(moveList, pokeList, i, element, element2));
					}
				}
				if (moves == 1) {
					seedList.push_back(pokemonSeed(moveList, pokeList, i, element));
				}
			}
		}
	}
}
seeds::~seeds() {
	seedSave.close();
}

void seeds::simulate() {
	if(output)
		std::cout << seedList.size() << " competitors!" << endl;

	int progressN[100];
	int progressCounter = 0;
	for (int i = 1; i <= 100; i++) {
		progressN[i - 1] = (seedList.size() * (seedList.size() + 1)) / 200 * i;
	}


		for (int i = 0; i < seedList.size(); i++) {
			#pragma omp parallel for
			for (int j = 0; j < seedList.size() - i; j++) {
				battle(&seedList[i], &seedList[j + i]);
			}
			if (progressCounter <= 99 && seedList.size() >= 1000 && output) {
				if (i * (seedList.size() + 1) - i * (i + 1) / 2 >= progressN[progressCounter]) {
					std::cout << progressCounter << "% ";
					if (progressCounter % 10 == 9)
						std::cout << endl;
					progressCounter++;
				}
			}
		}
		if(output)
			std::cout << endl;

	quickSort(seedList, 0, seedList.size() - 1);

	std::reverse(seedList.begin(), seedList.end());

	strongest.push_back(seedList[0]);

	for (int i = 0; i < seedList.size(); i++) {
		seedSave << seedList.at(i).GetPoke()->getID() << "," << seedList.at(i).GetMove(0)->getID() << "," << seedList.at(i).GetWin() << "," << seedList.at(i).GetDraw() << "," << seedList.at(i).GetLose() << endl;
	}
	seedSave << "BREAK" << endl;
}
void seeds::generate() {
	simulate();
	if (output)
		top100();
	int n = seedList.size() / 4;
	// +1 power of the top 25%
	for (int i = 0; i < n; i++) {
		seedList[i].AddPower();
	}
	//-1 power the weakest 25% of seeds
	for (int i = seedList.size() - 1; i > n * 3; i--) {
		seedList[i].SubtractPower();
		if (seedList[i].GetPower() < 1)
			seedList.erase(seedList.begin() + i);
	}
	/*// give top 25 1 power
	for (int i = 0; i < 25; i++) {
		seedList[i].AddPower();
	}
	// give top 10 1 power
	for (int i = 0; i < 10; i++) {
		seedList[i].AddPower();
	}
	// give top 5 1 power
	for (int i = 0; i < 5; i++) {
		seedList[i].AddPower();
	}*/
	//reset WLD of every seed
	for (int i = 0; i < seedList.size(); i++) {
		seedList[i].ClearWDL();
	}
	Extinct();
	generation++;
}
void seeds::Extinct() {
	bool firstExtinctPoke = true;
	bool firstExtinctMove = true;
	for (int i = 1; i <= pokeList->numPokes(); i++) {
		if (!pokeList->pokemonAtID(i)->isExtinct()) {
			pokeList->pokemonAtID(i)->setExtinct(generation);

		}
	}
	for (int i = 1; i <= moveList->getVector().size(); i++) {
		if (!moveList->FindID(i)->isExtinct()) {
			moveList->FindID(i)->setExtinct(generation);
		}
	}
	for (auto& element:seedList) {
		element.GetPoke()->unExtinct();
		element.GetMove(0)->unExtinct();
	}
	for (int i = 1; i <= pokeList->numPokes(); i++) {
		if (pokeList->pokemonAtID(i)->isExtinct() == generation) {
			if (firstExtinctPoke) {
				if(output)
					std::cout << "Pokemon that went extinct in generation " << generation << ":" << endl;
				firstExtinctPoke = false;
			}
			if(output)
				std::cout << pokeList->pokemonAtID(i)->getName() << endl;
		}
	}
	for (int i = 1; i <= moveList->getVector().size(); i++) {
		if (moveList->FindID(i)->isExtinct() == generation) {
			if (firstExtinctMove) {
				if(output)
					std::cout << "Moves that went extinct in generation " << generation << ":" << endl;
				firstExtinctMove = false;
			}
			if(output)
			std::cout << moveList->FindID(i)->getName() << endl;
		}
	}
	if(!firstExtinctMove || !firstExtinctPoke)
		if(output)
		std::cout << endl;
}

void seeds::battle(pokemonSeed* pokeA, pokemonSeed* pokeB) {
	int battleResult = 0;
	for (int k = 0; k <= bestOfNum; k++) {
		Battle temp = Battle(pokeA, pokeB, battleOutput);
		battleResult += temp.getResult();
		if (battleResult == bestOfNum / 2 + 1) {
			for (int i = 0; i < max(pokeA->GetPower(), pokeB->GetPower()); i++) {
				pokeA->AddWin();
				pokeB->AddLose();
			}
			return;
		}
		if (battleResult == -(bestOfNum / 2 + 1)) {
			for (int i = 0; i < max(pokeA->GetPower(), pokeB->GetPower()); i++) {
				pokeA->AddLose();
				pokeB->AddWin();
			}
			return;
		}
	}
	if (battleResult > 0) {
		for (int i = 0; i < max(pokeA->GetPower(), pokeB->GetPower()); i++) {
			pokeA->AddWin();
			pokeB->AddLose();
		}
	}
	else if (battleResult == 0) {
		for (int i = 0; i < max(pokeA->GetPower(), pokeB->GetPower()); i++) {
			pokeA->AddLose();
			pokeB->AddWin();
		}
	}
	else if (battleResult < 0) {
		for (int i = 0; i < max(pokeA->GetPower(), pokeB->GetPower()); i++) {
			pokeA->AddDraw();
			pokeB->AddDraw();
		}
	}
}

void seeds::top100() {
	std::cout << "Top 100" << endl;
	for (int i = 0; i < min(100, int(seedList.size())); i++)
		seedList.at(i).PrintSeed();
	std::cout << endl;
}
void seeds::showStrongest() {
	std::cout << "Strongest pokemon of each generation :" << endl;
	for (int i = 0; i < strongest.size(); i++) {
		std::cout << i << ":" << strongest[i].GetPoke()->getName() << "," << strongest[i].GetMove(0)->getName() << endl;
	}
	std::cout << endl;
}

void seeds::listID(int id) {
	std::cout << endl;
	for (auto &element : seedList) {
		if(element.GetPoke()->getID() == id)
			element.PrintSeed();
	}
}

int seeds::GetSize() {
	return seedList.size();
}

vector<pokemonSeed> seeds::getStrongest() {
	return strongest;
}