#include "pokemon.h"
#include "pokemonHelper.h"

using namespace std;

Pokemon::Pokemon(){
	//good practice
	name = "";
	id = -1;
	hp = -1;
	atk = -1;
	def = -1;
	spa = -1;
	spd = -1;
	spe = -1;
	type = -1;
	imgName = "";
}

string Pokemon::getName() {
	return name;
}
int Pokemon::getID() {
	return id;
}
string Pokemon::getImg() {
	return imgName.c_str();
}
string Pokemon::getIcon() {
	return iconName.c_str();
}
bool Pokemon::isDisabled() {
	return disabled;
}
int Pokemon::isExtinct() {
	return extinct;
}
int Pokemon::getHP() {
	return hp;
}
int Pokemon::getATK() {
	return atk;
}
int Pokemon::getDEF() {
	return def;
}
int Pokemon::getSPA() {
	return spa;
}
int Pokemon::getSPD() {
	return spd;
}
int Pokemon::getSPE() {
	return spe;
}
int Pokemon::getType() {
	return type;
}
int Pokemon::getType2(){
	return type2;
}

void Pokemon::setName(string element) {
	name = element;
	imgName = "data/images/" + element + ".png";
}
void Pokemon::setID(int element) {
	id = element;
	iconName = "data/icons/" + to_string(element) + ".png";
}
void Pokemon::Disable() {
	disabled = true;
	extinct = -1;
}
void Pokemon::Enable() {
	disabled = false;
	extinct = 0;
}
void Pokemon::setExtinct(int element) {
	extinct = element;
}
void Pokemon::unExtinct() {
	extinct = 0;
}
void Pokemon::setHP(int element) {
	hp = element;
}
void Pokemon::setATK(int element) {
	atk = element;
}
void Pokemon::setDEF(int element) {
	def = element;
}
void Pokemon::setSPA(int element) {
	spa = element;
}
void Pokemon::setSPD(int element) {
	spd = element;
}
void Pokemon::setSPE(int element) {
	spe = element;
}
void Pokemon::setType(int element) {
	type = element;
}
void Pokemon::setType2(int element) {
	type2 = element;
}

void Pokemon::addMove(int moveID) {
	moves.push_back(moveID);
}
bool Pokemon::hasMove(int moveID) {
	for (auto& it : moves) {
		if (it == moveID) {
			return true;
		}
	}
	return false;
}
vector<int> Pokemon::getMoves() {
	return moves;
}

void Pokemon::printPokemon(Moves* moveList) {
	cout << name << endl;
	cout << convertType(type);
	if (type2 != 0) {
		cout << " " << convertType(type2);
	}
	cout << endl;
	cout << "ID: " << id << endl;
	cout << "HP: " << hp << endl;
	cout << "ATK: " << atk << endl;
	cout <<	"DEF: " << def << endl;
	cout << "SPA: " << spa << endl;
	cout <<	"SPD: " << spd << endl;
	cout << "SPE: " << spe << endl;
	for (auto& element : moves) {
		cout << convertMove(element, moveList) << " ";
	}
	cout << endl;
}