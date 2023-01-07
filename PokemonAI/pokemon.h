#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "moves.h"

using namespace std;

class Pokemon {
private:
	string name;
	int id;
	bool disabled = false;
	int extinct = 0;

	int hp;
	int atk;
	int def;
	int spa;
	int spd;
	int spe;

	int type;
	int type2 = 0;

	vector<int> moves;

	string imgName;
	string iconName;

public:
	Pokemon();

	string getName();
	int getID();
	string getImg();
	string getIcon();
	bool isDisabled();
	int isExtinct();
	int getHP();
	int getATK();
	int getDEF();
	int getSPA();
	int getSPD();
	int getSPE();
	int getType();
	int getType2();

	void setName(string element);
	void setID(int element);
	void Disable();
	void Enable();
	void setExtinct(int element);
	void unExtinct();
	void setHP(int element);
	void setATK(int element);
	void setDEF(int element);
	void setSPA(int element);
	void setSPD(int element);
	void setSPE(int element);
	void setType(int element);
	void setType2(int element);

	void addMove(int moveID);
	bool hasMove(int moveID);
	vector<int> getMoves();

	void printPokemon(Moves* moveList);
};