#include "move.h"
#include "pokemonHelper.h"

using namespace std;

PokemonMove::PokemonMove() {
	//good practice
	id = -1;
	metaID = -1;
	power = -1;
	pp = -1;
	accuracy = -1;
	damageClass = -1;
	effect = -1;
	effectChance = -1;
	effectID = -1;
	priority = -1;
	type = -1;
};

int PokemonMove::getID() {
	return id;
};
string PokemonMove::getName() {
	return name;
};
bool PokemonMove::isDisabled() {
	return disabled;
}
int PokemonMove::isExtinct() {
	return extinct;
}
int PokemonMove::getType() {
	return type;
};
int PokemonMove::getPower() {
	return power;
};
int PokemonMove::getPP() {
	return pp;
};
int PokemonMove::getAccuracy() {
	return accuracy;
};
int PokemonMove::getPriority() {
	return priority;
};
bool PokemonMove::isPhysical() {
	if (damageClass == 2) {
		return true;
	}
	return false;
};
bool PokemonMove::isSpecial() {
	if (damageClass == 3) {
		return true;
	}
	return false;
};
bool PokemonMove::isStatus() {
	if (damageClass == 1) {
		return true;
	}
	return false;
}
int PokemonMove::getEffect() {
	return effect;
};
int PokemonMove::getEffectChance() {
	return effectChance;
};
int PokemonMove::getMetaID() {
	return metaID;
}
int PokemonMove::getEffectID() {
	return effectID;
}

void PokemonMove::setID(int element) {
	id = element;
};
void PokemonMove::setName(string element) {
	name = element;
};
void PokemonMove::setDisabled() {
	disabled = true;
}
void PokemonMove::setExtinct(int element) {
	extinct = element;
}
void PokemonMove::unExtinct() {
	extinct = 0;
}
void PokemonMove::setType(int element) {
	type = element;
};
void PokemonMove::setPower(int element) {
	power = element;
};
void PokemonMove::setPP(int element) {
	pp = element;
};
void PokemonMove::setAccuracy(int element) {
	accuracy = element;
};
void PokemonMove::setPriority(int element) {
	priority = element;
};
void PokemonMove::setDamageClass(int element) {
	damageClass = element;
};
void PokemonMove::setEffect(int element) {
	effect = element;
};
void PokemonMove::setEffectChance(int element) {
	effectChance = element;
};
void PokemonMove::setMetaID(int element) {
	metaID = element;
}
void PokemonMove::setEffectID(int element) {
	effectID = element;
}

void PokemonMove::printMove() {
	cout << name << endl;
	if (isSpecial()) {
		cout << "Special";
	}
	if (isPhysical()) {
		cout << "Physical";
	}
	if (isStatus()) {
		cout << "Status";
	}
	cout << " " << convertType(type) << endl;
	cout << "Power: " << power << " Accuracy: " << accuracy << " PP:" << pp << endl;
	cout << "MetaID: " << metaID << " EffectID:" << effectID << endl;
}