#include "battle.h"
#include "pokemonSeed.h"

using namespace std;

Battle::Battle(pokemonSeed* pokemonA, pokemonSeed* pokemonB, bool battleOutput) {
	this->pokemon[0] = pokemonA;
	this->pokemon[1] = pokemonB;
	this->battleOutput = battleOutput;
	turnNum = 0;
	result = 0;
	attacker = 0;
	
	for (int i = 0; i < 2; i++) {
		turnsCharging[i] = 0;
		lockedMove[i] = false;
		flying[i] = 0;
		flinched[i] = 0;
		nvStatus[i] = 0; // 0none 1paralysis 2sleep 3freeze 4burn 5poison 6toxic
		turnsToxic[i] = 0;
		turnsSlept[i] = 0;
		turnsAsleep[i] = 0;
		turnsTrapped[i] = 0;
		turnsTrappedFor[i] = 0;
		turnsConfused[i] = 0;
		turnsConfusedFor[i] = 0;
		turnsLocked[i] = 0;
		turnsLockedFor[i] = 0;
		

		stats[i] = pokemon[i]->GetPoke();

		hp[i] = int(floor(0.01 * (2 * stats[i]->getHP() + 31 + floor(0.25 * 0)) * 100) + 100 + 10);
		atk[i] = int((floor(0.01 * (2 * stats[i]->getATK() + 31 + floor(0.25 * 0)) * 100) + 5) * 1);//the 1 is for nature, unimplemented
		def[i] = int((floor(0.01 * (2 * stats[i]->getDEF() + 31 + floor(0.25 * 0)) * 100) + 5) * 1);
		spa[i] = int((floor(0.01 * (2 * stats[i]->getSPA() + 31 + floor(0.25 * 0)) * 100) + 5) * 1);
		spd[i] = int((floor(0.01 * (2 * stats[i]->getSPD() + 31 + floor(0.25 * 0)) * 100) + 5) * 1);
		spe[i] = int((floor(0.01 * (2 * stats[i]->getSPE() + 31 + floor(0.25 * 0)) * 100) + 5) * 1);

		hpStage[i] = 0;
		atkStage[i] = 0;
		defStage[i] = 0;
		spaStage[i] = 0;
		spdStage[i] = 0;
		speStage[i] = 0;
		accStage[i] = 0;
		evaStage[i] = 0;

		currentHP[i] = hp[i];
		for (int j = 0; j < 1; j++) {//TEMP change to j < 4 later for 4 moves
			moves[i][j] = pokemon[i]->GetMove(-j);
			movePP[i][j] = moves[i][j]->getPP();
		}
	}
	
	Calculate();
}

void Battle::Calculate() {
	while (currentHP[0] > 0 && currentHP[1] > 0 && turnNum < 101) {
		turnNum++;
		Turn();
	}
	if (turnNum > 100) {
		result = 0;
		if (battleOutput)
			cout << stats[0]->getName() << " with " << moves[0][0]->getName() << " stalls out " << stats[1]->getName() << " with " << moves[1][1]->getName() << endl;
		return;
	}
	if (currentHP[0] > 0) {
		result = 1;
		if (battleOutput)
			cout << stats[0]->getName() << " with " << moves[0][0]->getName() << " beats " << stats[1]->getName() << " with " << moves[1][0]->getName() << endl;
	}
	else {
		result = -1;
		if (battleOutput)
			cout << stats[1]->getName() << " with " << moves[1][0]->getName() << " beats " << stats[0]->getName() << " with " << moves[0][0]->getName() << endl;

	}
}

void Battle::Turn() {
	ChooseMove();

	attacker = Speed();

	Move();

	if (currentHP[0] <= 0 || currentHP[1] <= 0) {
		return;
	}

	attacker = abs(attacker - 1);

	
	Move();

	for (int i = 0; i < 2; i++) {
		switch (nvStatus[i]) {
		case 2://sleep
			turnsAsleep[i]++;
			break;
		case 4://burn
		case 5://poison
			currentHP[i] -= int(floor(hp[i] / double(8)));
			break;
		case 6://toxic
			currentHP[i] -= int(floor(hp[i] * (turnsToxic[i] + 1) / double(16)));
			turnsToxic[i]++;
			break;
		}
		flinched[i] = 0;
		if (turnsTrappedFor[i]) {
			currentHP[i] -= int(floor(hp[i] / double(8)));
			turnsTrapped[i]++;
			if (turnsTrapped[i] == turnsTrappedFor[i]) {
				turnsTrapped[i] = 0;
				turnsTrappedFor[i] = 0;
			}
		}
		if (turnsConfusedFor[i]) {
			turnsConfused[i]++;
			if (turnsConfused[i] == turnsConfusedFor[i]) {
				turnsConfused[i] = 0;
				turnsConfusedFor[i] = 0;
			}
		}
	}
}

void Battle::Move(){
	int damage = 0;
	int critRate = 24;
	double critical = 1;
	float STAB = 1;
	float moveSpecificMulti = 1;

	int numHits;

	if (flinched[attacker])
		return;

	if (turnsConfusedFor[attacker]) {
		if (rand() % 3 == 0) {
			currentHP[attacker] -= int(round(round(round(round((((2 * 100 / 5) + 2) * 40 * currentatk(attacker) / currentdef(abs(attacker))) / 50) + 2) * (rand() % 16 + 85) / 100)));
			return;
		}
	}

	if (chosenMove[attacker]->getEffectID() == 84) {//metronome
		chosenMove[attacker] = pokemon[attacker]->GetMove(rand() % 165); //UPDATE needs to be updated for size of moveList later
	}

	switch (nvStatus[attacker]) {
	case 1://paralysis
		if (rand() % 100 < 25) {
			if(battleOutput)
				cout << stats[attacker]->getName() << " is paralyzed!" << endl;
			return;
		}
		break;
	case 2://sleep
		if (turnsAsleep[attacker] == turnsSlept[attacker]) {
			nvStatus[attacker] = 0;
			turnsAsleep[attacker] = 0;
			if (battleOutput)
				cout << stats[attacker]->getName() << " wakes up!" << endl;
			break;
		}
		if (battleOutput)
			cout << stats[attacker]->getName() << " is fast asleep..." << endl;
		return;
	case 3://freeze
		if (rand() % 100 < 20) {
			nvStatus[attacker] = 0;
			if (battleOutput)
				cout << stats[attacker]->getName() << " thaws out!" << endl;
			break;
		}
		if (battleOutput)
			cout << stats[attacker]->getName() << " is frozen solid!" << endl;
		return;
	}

	if(lockedMove[attacker]){
		switch (chosenMove[attacker]->getID()) {
		case 13://razor-wind
			lockedMove[attacker] = 0;
			break;
		case 19://fly
			lockedMove[attacker] = 0;
			flying[attacker] = 0;
			break;
		case 63://hyper-beam
			if (battleOutput)
				cout << stats[attacker]->getName() << " has to recharge after using " << chosenMove[attacker]->getName() << "!" << endl;
			lockedMove[attacker] = 0;
			return;
		case 76://solar-beam
			lockedMove[attacker] = 0;
			break;
		case 143://sky-attack
			lockedMove[attacker] = 0;
			break;
		}
	}

	switch (chosenMove[attacker]->getEffectID()) {
	case 2://sing, sleep-powder, hypnosis, lovely-kiss, spore (sleep moves)
		if (!hits())
			return;
		nvStatus[abs(attacker - 1)] = 2;
		turnsSlept[abs(attacker - 1)] = rand() % 3 + 1;
		return;
	case 9://dream-eater
		if (nvStatus[abs(attacker - 1)] != 2)
			return;
	case 11://meditate, sharpen
		if(atkStage[attacker] < 6)
			atkStage[attacker]++;
		return;
	case 12://harden, withdraw
		if (defStage[attacker] < 6)
			defStage[attacker]++;
		return;
	case 19://growl
		if (atkStage[abs(attacker - 1)] > -6)
			atkStage[abs(attacker - 1)]--;
		return;
	case 20://leer
		if (!hits())
			return;
		if (defStage[abs(attacker - 1)] > -6)
			defStage[abs(attacker - 1)]--;
		return;
	case 24://sand-attack, smokescreen, kinesis, flash
		if (!hits())
			return;
		if (accStage[abs(attacker - 1)] > -6)
			accStage[abs(attacker - 1)]--;
		return;
	case 28://petal-dance
		if (!turnsLocked[attacker]) {
			lockedMove[attacker] = true;
			turnsLockedFor[attacker] = rand() % 2 + 2;
		}
		else {
			turnsLocked[attacker]++;
		}
		if (turnsLocked[attacker] == turnsLockedFor[attacker]) {
			turnsLocked[attacker] = 0;
			turnsLockedFor[attacker] = 0;
			turnsConfusedFor[attacker] = rand() % 4 + 2;
		}
		break;
	case 30://double-slap, comet-punch, fury-attack, pin-missile, spike-cannon, barrage, fury-swipes
		if (!hits())
			return;
		numHits = int(rand() % 8);
		if (numHits == 7) {
			numHits = 5;
		}
		else if(numHits == 6){
			numHits = 4;
		}
		else if (numHits > 2) {
			numHits = 3;
		}
		else {
			numHits = 2;
		}
		damage = int(round(round(round(round(round((((2 * 100 / 5) + 2) * chosenMove[attacker]->getPower() * currentatk(attacker) / currentdef(abs(attacker - 1))) / 50) + 2) * (rand() % 16 + 85) / 100) * typeEffectiveness(chosenMove[attacker]->getType(), stats[abs(attacker - 1)]->getType(), stats[abs(attacker - 1)]->getType2())) * STAB));// *burn;
		for (int i = 0; i < numHits; i++) {
			critical = 1;
			if (rand() % critRate == 0)
				critical = 1.5;
			currentHP[abs(attacker - 1)] -= int(floor(damage * critical));
		}
		return;
	case 33://soft-boiled, recover, milk-drink, slack-off, heal-order
		currentHP[attacker] += int(round(hp[attacker] / 2));
		if (currentHP[attacker] > hp[attacker])
			currentHP[attacker] = hp[attacker];
		if (battleOutput)
			cout << stats[attacker]->getName() << " recovers with " << chosenMove[attacker]->getName() << endl;
		return;
	case 34://toxic
		if (!hits())
			return;
		nvStatus[abs(attacker - 1)] = 6;
		return;
	case 35://pay-day
		break;
	case 38://rest
		currentHP[attacker] = hp[attacker];
		nvStatus[attacker] = 2;
		turnsSlept[attacker] = 2;
		if (battleOutput)
			cout << stats[attacker]->getName() << " uses " << chosenMove[attacker]->getName() << "!"<< endl;
		return;
	case 39://fissure, guillotine, horn-drill, sheer-cold
		if (!hits())
			return;
		if (rand() % 100 < chosenMove[attacker]->getAccuracy()) {
			if (battleOutput) 
				cout << stats[attacker]->getName() << " OHKOs with " << chosenMove[attacker]->getName() << "!" << endl;
			currentHP[abs(attacker - 1)] = 0;
		}
		return;
	case 40://razor-wind
		if (turnsCharging[attacker] == 0) {
			lockedMove[attacker] = 1;
			turnsCharging[attacker]++;
			if (battleOutput)
				cout << stats[attacker]->getName() << " whips up a whirlwind!" << endl;
			return;
		}
		critRate = 8;
		break;
	case 41://super-fang
		if (!hits())
			return;
		currentHP[abs(attacker - 1)] = int(round(currentHP[abs(attacker - 1)] / 2));
		return;
	case 42://dragon-rage
		if (!hits())
			return;
		currentHP[abs(attacker - 1)] -= 40;
		return;
	case 44://karate-chop, razor-leaf, crabhammer, slash
		critRate = 8;
		break;
	case 45://double-kick, bonemerang
		if (!hits())
			return;
		damage = int(round(round(round(round(round((((2 * 100 / 5) + 2) * chosenMove[attacker]->getPower() * currentatk(attacker) / currentdef(abs(attacker - 1))) / 50) + 2) * (rand() % 16 + 85) / 100) * typeEffectiveness(chosenMove[attacker]->getType(), stats[abs(attacker - 1)]->getType(), stats[abs(attacker - 1)]->getType2())) * STAB));// *burn;
		for (int i = 0; i < 2; i++) {
			critical = 1;
			if (rand() % critRate == 0)
				critical = 1.5;
			currentHP[abs(attacker - 1)] -= int(floor(damage * critical));
		}
		return;
	case 51://swords-dance
		if (atkStage[attacker] < 6)
			atkStage[attacker] ++;
		if (atkStage[attacker] < 6)
			atkStage[attacker] ++;
		return;
	case 52://barrier, acid-armor
		if (defStage[attacker] < 6)
			defStage[attacker] ++;
		if (defStage[attacker] < 6)
			defStage[attacker] ++;
		return;
	case 53://agility
		if (speStage[attacker] < 6)
			speStage[attacker]++;
		if (speStage[attacker] < 6) 
			speStage[attacker]++;
		return;
	case 55://amnesia
		if (spdStage[attacker] < 6)
			spdStage[attacker]++;
		if (spdStage[attacker] < 6)
			spdStage[attacker]++;
		return;
	case 60://screech
		if (!hits())
			return;
		if (defStage[abs(attacker - 1)] > -6)
			defStage[abs(attacker - 1)]--;
		if (defStage[abs(attacker - 1)] > -6)
			defStage[abs(attacker - 1)]--;
		break;
	case 61://string-shot
		if (!hits())
			return;
		if (speStage[abs(attacker - 1)] > -6)
			speStage[abs(attacker - 1)]--;
		if (speStage[abs(attacker - 1)] > -6)
			speStage[abs(attacker - 1)]--;
		return;
	case 67://poison-powder
		if (!hits())
			return;
		nvStatus[abs(attacker - 1)] = 5;
		return;
	case 68://glare
		if (!hits())
			return;
		nvStatus[abs(attacker - 1)] = 1;
		return;
	case 76://sky-attack
		if (turnsCharging[attacker] == 0) {
			lockedMove[attacker] = 1;
			turnsCharging[attacker]++;
			if (battleOutput)
				cout << stats[attacker]->getName() << " becomes cloaked in a harsh light!" << endl;
			return;
		}
		critRate = 8;
		break;
	case 86://splash
		if(battleOutput)
			cout << stats[attacker]->getName() << " splashes around..." << endl;
		return;
	case 88://seismic-toss, night-shade
		if (!hits())
			return;
		currentHP[abs(attacker - 1)] -= 100;
		return;
	case 146://skull-bash
		if (!turnsCharging[attacker]) {
			lockedMove[attacker] = true;
			turnsCharging[attacker]++;
			defStage[attacker]++;
			if (battleOutput)
				cout << stats[attacker]->getName() << " lowers their head due to " << chosenMove[attacker]->getName() << "!" << endl;
			return;
		}
		break;
	case 150://gust
		if (flying[abs(attacker - 1)])
			moveSpecificMulti = 2;
		break;
	case 152://solar-beam
		if (turnsCharging[attacker] == 0) {
			lockedMove[attacker] = 1;
			turnsCharging[attacker]++;
			if (battleOutput)
				cout << stats[attacker]->getName() << " begins charging " << chosenMove[attacker]->getName() << "!" << endl;
			return;
		}
		break;
	case 156://fly
		if (turnsCharging[attacker] == 0) {
			lockedMove[attacker] = 1;
			turnsCharging[attacker]++;
			flying[attacker] = 1;
			if (battleOutput)
				cout << stats[attacker]->getName() << " flies up high!" << endl;
			return;
		}
		break;
	case 157://defensive-curl
		if (defStage[attacker] < 6)
			defStage[attacker]++;
		return;
	case 255://struggle
		damage = int(round(round(round((((2 * 100 / 5) + 2) * 50 * currentatk(attacker) / currentdef(abs(attacker - 1))) / 50) + 2) * (rand() % 16 + 85) / 100));
		currentHP[abs(attacker - 1)] -= damage;
		if (battleOutput)
			cout << stats[attacker]->getName() << " deals " << damage << " damage to " << stats[abs(attacker - 1)]->getName() << " with " << chosenMove[attacker]->getName() << endl;
		if (currentHP[abs(attacker - 1)] < 0)
			return;
		currentHP[attacker] -= int(round(hp[attacker] * 0.25));
		if(battleOutput)
			cout << stats[attacker]->getName() << " struggles!" << endl;
		return;
	case 317://growth
		if (atkStage[attacker] < 6)
			atkStage[attacker]++;
		if (spaStage[attacker] < 6)
			spaStage[attacker]++;
		return;
	}

	if (chosenMove[attacker]->isStatus())
		return;
	
	//move deals damage
	if (chosenMove[attacker]->getMetaID() == 0 || chosenMove[attacker]->getMetaID() == 4 || chosenMove[attacker]->getMetaID() == 6 || chosenMove[attacker]->getMetaID() == 7 || chosenMove[attacker]->getMetaID() == 8) {
		
		if (!hits()) {
			if (chosenMove[attacker]->getEffectID() == 46)
				currentHP[attacker] -= int(round(hp[attacker] / 2));
			return;
		}

		if (rand() % critRate == 0)
			critical = 1.5;

		if (chosenMove[attacker]->getType() == stats[attacker]->getType() || chosenMove[attacker]->getType() == stats[attacker]->getType2())
			STAB = 1.5;

		if (chosenMove[attacker]->isPhysical()) {//currently factoring: power, base stats, type effectiveness, STAB, moveSpecificMulti
			damage = int(round(round(round(round(round(round(round((((2 * 100 / 5) + 2) * chosenMove[attacker]->getPower() * currentatk(attacker) / currentdef(abs(attacker-1))) / 50) + 2) * critical) * (rand() % 16 + 85) / 100) * typeEffectiveness(chosenMove[attacker]->getType(), stats[abs(attacker - 1)]->getType(), stats[abs(attacker - 1)]->getType2())) * STAB) * moveSpecificMulti));
		}
		else if (chosenMove[attacker]->isSpecial()) {
			damage = int(round(round(round(round(round(round(round((((2 * 100 / 5) + 2) * chosenMove[attacker]->getPower() * currentspa(attacker) / currentspd(abs(attacker - 1))) / 50) + 2) * critical) * (rand() % 15 + 85) / 100) * typeEffectiveness(chosenMove[attacker]->getType(), stats[abs(attacker - 1)]->getType(), stats[abs(attacker - 1)]->getType2())) * STAB) * moveSpecificMulti));
		}
		if (battleOutput)
			cout << stats[attacker]->getName() << " deals " << damage << " damage to " << stats[abs(attacker - 1)]->getName() << " with " << chosenMove[attacker]->getName() << endl;
		currentHP[abs(attacker - 1)] -= damage;
		if (currentHP[abs(attacker - 1)] < 0)
			return;
		turnsCharging[attacker] = 0;
	}

	//hit confirm effects
	switch (chosenMove[attacker]->getEffectID()) {
	case 3://poison-sting, smog, sludge (poison moves)
		if (stats[abs(attacker - 1)]->getType() == 4 || stats[abs(attacker - 1)]->getType() == 4 || stats[abs(attacker - 1)]->getType() == 9 || stats[abs(attacker - 1)]->getType() == 9)
			break;//steel and poison immune to poison
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			nvStatus[abs(attacker - 1)] = 5;
		break;
	case 4://absorb, mega-drain, leech-life
		currentHP[attacker] += int(round(damage / 2));
		break;
	case 5://fire-punch, flamethrower, fire-blast (burn moves)
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			nvStatus[abs(attacker - 1)] = 4;
		break;
	case 6://ice-punch, ice-beam (freeze moves)
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			nvStatus[abs(attacker - 1)] = 3;
		break;
	case 7://thunder-punch, body-slam, thunder-shock, thunderbolt, lick (paralysis moves)
		if (stats[abs(attacker - 1)]->getType() == 13 || stats[abs(attacker - 1)]->getType() == 13)
			break;//electric immunte to paralysis
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			nvStatus[abs(attacker - 1)] = 1;
		break;
	case 8://explosion & selfdestruct
		currentHP[attacker] = 0;
		if (battleOutput)
			cout << stats[attacker]->getName() << " faints after using " << chosenMove[attacker]->getName() << "!" << endl;
		break;
	case 9://dream-eater
		currentHP[attacker] += int(round(damage / 2));
		break;
	case 32://rolling-kick, headbutt, bite, bone-club, waterfall, rock-slide, hyper-fang (flinch moves)
		if (rand() % 100 < chosenMove[attacker]->getEffectChance()) {
			flinched[abs(attacker - 1)] = 1;
			if (battleOutput)
				cout << stats[abs(attacker - 1)]->getName() << " flinched!" << endl;
		}
		break;
	case 43://wrap, bind, fire-spin, clamp
		turnsTrapped[abs(attacker - 1)] = rand() % 2 + 4;
		break;
	case 49://submission
		currentHP[attacker] -= int(floor(damage / 4));
		if (battleOutput)
			cout << stats[attacker]->getName() << " takes " << int(floor(damage / 4)) << " damage from recoil!" << endl;
		break;
	case 71://bubble-beam, constrict, bubble
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			if (speStage[abs(attacker - 1)] > -6)
				speStage[abs(attacker - 1)]--;
		break;
	case 73://psychic, acid
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			if (spdStage[abs(attacker - 1)] > -6)
				spdStage[abs(attacker - 1)]--;
		break;
	case 81://hyper-beam
		lockedMove[attacker] = 1;
		break;
	case 153://thunder
		if (stats[abs(attacker - 1)]->getType() == 13 || stats[abs(attacker - 1)]->getType() == 13)
			break;//electric immunte to paralysis
		if (rand() % 100 < chosenMove[attacker]->getEffectChance())
			nvStatus[abs(attacker - 1)] = 1;
		break;
	case 199://double-edge
		currentHP[attacker] -= int(floor(damage / 3));
		if (battleOutput)
			cout << stats[attacker]->getName() << " takes " << int(floor(damage / 3)) << " damage from recoil!" << endl;
		break;
	}
}

bool Battle::hits() {
	if (flying[abs(attacker - 1)]) {
		if (chosenMove[attacker]->getID() != 117 && chosenMove[attacker]->getID() != 129 && chosenMove[attacker]->getID() != 16 && chosenMove[attacker]->getID() != 87 && chosenMove[attacker]->getID() != 239 && chosenMove[attacker]->getID() != 18 && chosenMove[attacker]->getID() != 327 && chosenMove[attacker]->getID() != 542 && chosenMove[attacker]->getID() != 479 && chosenMove[attacker]->getID() != 614)
			return false;
	}

	if (chosenMove[attacker]->getEffectID() == 18)
		return true;

	if (chosenMove[attacker]->getAccuracy() != -1) {
		if (rand() % 100 > chosenMove[attacker]->getAccuracy()) {
			if (battleOutput)
				cout << stats[attacker]->getName() << " misses with " << chosenMove[attacker]->getName() << "!" << endl;
			return false;
		}
	}
	if(chosenMove[attacker]->getID() != 28) //exemption from flying-type nullification for certain ground moves; sand-attack
		if (typeEffectiveness(chosenMove[attacker]->getType(), stats[abs(attacker - 1)]->getType(), stats[abs(attacker - 1)]->getType2()) == 0)
			return false;

	return true;
}
int Battle::Speed() {
	if (chosenMove[0]->getPriority() > chosenMove[1]->getPriority())//104, quick-attack
		return 0;
	if (chosenMove[1]->getPriority() > chosenMove[0]->getPriority())
		return 1;
	if (currentspe(0) > currentspe(1))
		return 0;
	if (currentspe(1) > currentspe(0))
		return 1;
	return int(floor(rand() % 2));
}
void Battle::ChooseMove() {
	for (int i = 0; i < 2; i++) {
		if (!lockedMove[i]) {
			int action = pokemon[i]->GetAction(this, i);
			if (!action) {
				chosenMove[i] = pokemon[i]->GetMove(165); //struggle, id 165
			}
			if (action < 5 && action > 0) {
				chosenMove[i] = moves[i][action - 1];
				movePP[i][action - 1]--;
			}
		}
	}
}

int Battle::currentatk(int attacker) {
	if (!atkStage[attacker]) {
		if (nvStatus[attacker] == 4)
			return int(round(spe[attacker] * 0.5));
		return spe[attacker];
	}
	if (atkStage[attacker] > 0) {
		if (nvStatus[attacker] == 4)
			return int(round(spe[attacker] * ((float(2) + atkStage[attacker]) / 2) * 0.5));
		return int(floor(spe[attacker] * ((float(2) + atkStage[attacker]) / 2)));
	}
	if (atkStage[attacker] < 0) {
		if (nvStatus[attacker] == 4)
			return int(round(spe[attacker] * ((float(2) / 2 - atkStage[attacker])) * 0.5));
		return int(floor(spe[attacker] * ((float(2) / 2 - atkStage[attacker]))));
	}
	cout << "ERROR stat stage broke" << endl;
	return 0;
}
int Battle::currentdef(int attacker) {
	if (!defStage[attacker])
		return def[attacker];
	if (defStage[attacker] > 0)
		return int(floor(def[attacker] * ((float(2) + defStage[attacker]) / 2)));
	if (defStage[attacker] < 0)
		return int(floor(def[attacker] * ((float(2) / 2 - defStage[attacker]))));
	cout << "ERROR stat stage broke" << endl;
	return 0;
}
int Battle::currentspa(int attacker) {
	if (!spaStage[attacker])
		return spa[attacker];
	if (spaStage[attacker] > 0)
		return int(floor(spa[attacker] * ((float(2) + spaStage[attacker]) / 2)));
	if (spaStage[attacker] < 0)
		return int(floor(spa[attacker] * ((float(2) / 2 - spaStage[attacker]))));
	cout << "ERROR stat stage broke" << endl;
	return 0;
}
int Battle::currentspd(int attacker) {
	if (!spdStage[attacker])
		return spd[attacker];
	if (spdStage[attacker] > 0)
		return int(floor(spd[attacker] * ((float(2) + spdStage[attacker]) / 2)));
	if (spdStage[attacker] < 0)
		return int(floor(spd[attacker] * ((float(2) / 2 - spdStage[attacker]))));
	cout << "ERROR stat stage broke" << endl;
	return 0;
}
int Battle::currentspe(int attacker) {
	if (!speStage[attacker]) {
		if (nvStatus[attacker] == 1)
			return int(round(spe[attacker] * 0.5));
		return spe[attacker];
	}	
	if (speStage[attacker] > 0) {
		if (nvStatus[attacker] == 1)
			return int(round(spe[attacker] * ((float(2) + speStage[attacker]) / 2) * 0.5));
		return int(floor(spe[attacker] * ((float(2) + speStage[attacker]) / 2)));
	}
	if (speStage[attacker] < 0) {
		if (nvStatus[attacker] == 1)
			return int(round(spe[attacker] * ((float(2) / 2 - speStage[attacker])) * 0.5));
		return int(floor(spe[attacker] * ((float(2) / 2 - speStage[attacker]))));
	}
	cout << "ERROR stat stage broke" << endl;
	return 0;
}

int Battle::getResult() {
	return result;
}

int Battle::getPP(int selfID, int index) {
	return movePP[selfID][index];
}