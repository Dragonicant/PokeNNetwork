#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class PokemonMove {
private:
	int id;
	string name;
	bool disabled = false;
	int extinct = 0;
	int type;
	int power;
	int pp;
	int accuracy;
	int priority;
	int damageClass;
	int effect;
	int effectChance;
	int metaID;
	int effectID;

public:
	PokemonMove();

	int getID();
	string getName();
	bool isDisabled();
	int isExtinct();
	int getType();
	int getPower();
	int getPP();
	int getAccuracy();
	int getPriority();
	bool isPhysical();
	bool isSpecial();
	bool isStatus();
	int getEffect();
	int getEffectChance();
	int getMetaID();
	int getEffectID();

	void setID(int element);
	void setName(string element);
	void setDisabled();
	void setExtinct(int element);
	void unExtinct();
	void setType(int element);
	void setPower(int element);
	void setPP(int element);
	void setAccuracy(int element);
	void setPriority(int element);
	void setDamageClass(int element);
	void setEffect(int element);
	void setEffectChance(int element);
	void setMetaID(int element);
	void setEffectID(int element);

	void printMove();
};