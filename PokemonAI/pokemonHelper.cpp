#include "pokemonHelper.h"

string convertType(int type) {
	switch (type) {
	case 1:
		return "Normal";
	case 2:
		return "Fighting";
	case 3:
		return "Flying";
	case 4:
		return "Poison";
	case 5:
		return "Ground";
	case 6:
		return "Rock";
	case 7:
		return "Bug";
	case 8:
		return "Ghost";
	case 9:
		return "Steel";
	case 10:
		return "Fire";
	case 11:
		return "Water";
	case 12:
		return "Grass";
	case 13:
		return "Electric";
	case 14:
		return "Psychic";
	case 15:
		return "Ice";
	case 16:
		return "Dragon";
	case 17:
		return "Dark";
	case 18:
		return "Fairy";
	}
	return "Typeless";
}
string convertMove(int moveID, Moves* moveList) {
	return moveList->getVector().at(moveID - 1).getName();
}
float typeEffectiveness(int attackingType, int defendingType, int defendingType2) {
	float effectiveness = 1;
	switch (attackingType) {
	case 1:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 0.5;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 0;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 2:
		switch (defendingType) {
		case 1:
			effectiveness *= 2; 
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 0.5;
			break;
		case 4:
			effectiveness *= 0.5;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 2;
			break;
		case 7:
			effectiveness *= 0.5;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 2;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 0.5;
			break;
		case 15:
			effectiveness *= 2;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 2;
			break;
		case 18:
			effectiveness *= 0.5;
			break;
		}
		break;
	case 3:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 2;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 0.5;
			break;
		case 7:
			effectiveness *= 2;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 2;
			break;
		case 13:
			effectiveness *= 0.5;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 4:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 0.5;
			break;
		case 5:
			effectiveness *= 0.5;
			break;
		case 6:
			effectiveness *= 0.5;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 0.5;
			break;
		case 9:
			effectiveness *= 0;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 2;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 2;
			break;
		}
		break;
	case 5:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 0;
			break;
		case 4:
			effectiveness *= 2;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 2;
			break;
		case 7:
			effectiveness *= 0.5;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 2;
			break;
		case 10:
			effectiveness *= 2;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 0.5;
			break;
		case 13:
			effectiveness *= 2;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 6:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 0.5;
			break;
		case 3:
			effectiveness *= 2;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 0.5;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 2;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 2;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 2;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 7:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 0.5;
			break;
		case 3:
			effectiveness *= 0.5;
			break;
		case 4:
			effectiveness *= 0.5;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 0.5;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 0.5;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 2;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 2;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 2;
			break;
		case 18:
			effectiveness *= 0.5;
			break;
		}
		break;
	case 8:
		switch (defendingType) {
		case 1:
			effectiveness *= 0;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 2;
			break;
		case 9:
			effectiveness *= 1;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 2;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 0.5;
			break;
		}
		break;
	case 9:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 2;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 0.5;
			break;
		case 11:
			effectiveness *= 0.5;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 0.5;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 2;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 2;
			break;
		}
		break;
	case 10:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 0.5;
			break;
		case 7:
			effectiveness *= 2;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 2;
			break;
		case 10:
			effectiveness *= 0.5;
			break;
		case 11:
			effectiveness *=0.5 ;
			break;
		case 12:
			effectiveness *= 2;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 2;
			break;
		case 16:
			effectiveness *= 0.5;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 11:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 2;
			break;
		case 6:
			effectiveness *= 2;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 1;
			break;
		case 10:
			effectiveness *= 2;
			break;
		case 11:
			effectiveness *= 0.5;
			break;
		case 12:
			effectiveness *= 0.5;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 0.5;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 12:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 0.5;
			break;
		case 4:
			effectiveness *= 0.5;
			break;
		case 5:
			effectiveness *= 2;
			break;
		case 6:
			effectiveness *= 2;
			break;
		case 7:
			effectiveness *= 0.5;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 0.5;
			break;
		case 11:
			effectiveness *= 2;
			break;
		case 12:
			effectiveness *= 0.5;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 0.5;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 13:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 2;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 0;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 1;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 2;
			break;
		case 12:
			effectiveness *= 0.5;
			break;
		case 13:
			effectiveness *= 0.5;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 0.5;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 14:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 2;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 2;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 0.5;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 0;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 15:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 2;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 2;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 0.5;
			break;
		case 11:
			effectiveness *= 0.5;
			break;
		case 12:
			effectiveness *= 2;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 0.5;
			break;
		case 16:
			effectiveness *= 2;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	case 16:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 1;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 2;
			break;
		case 17:
			effectiveness *= 1;
			break;
		case 18:
			effectiveness *= 0;
			break;
		}
		break;
	case 17:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 0.5;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 1;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 2;
			break;
		case 9:
			effectiveness *= 1;
			break;
		case 10:
			effectiveness *= 1;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 2;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 1;
			break;
		case 17:
			effectiveness *= 0.5;
			break;
		case 18:
			effectiveness *= 0.5;
			break;
		}
		break;
	case 18:
		switch (defendingType) {
		case 1:
			effectiveness *= 1;
			break;
		case 2:
			effectiveness *= 2;
			break;
		case 3:
			effectiveness *= 1;
			break;
		case 4:
			effectiveness *= 0.5;
			break;
		case 5:
			effectiveness *= 1;
			break;
		case 6:
			effectiveness *= 1;
			break;
		case 7:
			effectiveness *= 1;
			break;
		case 8:
			effectiveness *= 1;
			break;
		case 9:
			effectiveness *= 0.5;
			break;
		case 10:
			effectiveness *= 0.5;
			break;
		case 11:
			effectiveness *= 1;
			break;
		case 12:
			effectiveness *= 1;
			break;
		case 13:
			effectiveness *= 1;
			break;
		case 14:
			effectiveness *= 1;
			break;
		case 15:
			effectiveness *= 1;
			break;
		case 16:
			effectiveness *= 2;
			break;
		case 17:
			effectiveness *= 2;
			break;
		case 18:
			effectiveness *= 1;
			break;
		}
		break;
	}
	if (defendingType2 != 0) {
		switch (attackingType) {
		case 1:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 0.5;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 0;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 2:
			switch (defendingType2) {
			case 1:
				effectiveness *= 2;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 0.5;
				break;
			case 4:
				effectiveness *= 0.5;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 2;
				break;
			case 7:
				effectiveness *= 0.5;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 2;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 0.5;
				break;
			case 15:
				effectiveness *= 2;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 2;
				break;
			case 18:
				effectiveness *= 0.5;
				break;
			}
			break;
		case 3:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 2;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 0.5;
				break;
			case 7:
				effectiveness *= 2;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 2;
				break;
			case 13:
				effectiveness *= 0.5;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 4:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 0.5;
				break;
			case 5:
				effectiveness *= 0.5;
				break;
			case 6:
				effectiveness *= 0.5;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 0.5;
				break;
			case 9:
				effectiveness *= 0;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 2;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 2;
				break;
			}
			break;
		case 5:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 0;
				break;
			case 4:
				effectiveness *= 2;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 2;
				break;
			case 7:
				effectiveness *= 0.5;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 2;
				break;
			case 10:
				effectiveness *= 2;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 0.5;
				break;
			case 13:
				effectiveness *= 2;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 6:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 0.5;
				break;
			case 3:
				effectiveness *= 2;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 0.5;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 2;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 2;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 2;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 7:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 0.5;
				break;
			case 3:
				effectiveness *= 0.5;
				break;
			case 4:
				effectiveness *= 0.5;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 0.5;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 0.5;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 2;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 2;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 2;
				break;
			case 18:
				effectiveness *= 0.5;
				break;
			}
			break;
		case 8:
			switch (defendingType2) {
			case 1:
				effectiveness *= 0;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 2;
				break;
			case 9:
				effectiveness *= 1;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 2;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 0.5;
				break;
			}
			break;
		case 9:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 2;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 0.5;
				break;
			case 11:
				effectiveness *= 0.5;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 0.5;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 2;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 2;
				break;
			}
			break;
		case 10:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 0.5;
				break;
			case 7:
				effectiveness *= 2;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 2;
				break;
			case 10:
				effectiveness *= 0.5;
				break;
			case 11:
				effectiveness *= 0.5;
				break;
			case 12:
				effectiveness *= 2;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 2;
				break;
			case 16:
				effectiveness *= 0.5;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 11:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 2;
				break;
			case 6:
				effectiveness *= 2;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 1;
				break;
			case 10:
				effectiveness *= 2;
				break;
			case 11:
				effectiveness *= 0.5;
				break;
			case 12:
				effectiveness *= 0.5;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 0.5;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 12:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 0.5;
				break;
			case 4:
				effectiveness *= 0.5;
				break;
			case 5:
				effectiveness *= 2;
				break;
			case 6:
				effectiveness *= 2;
				break;
			case 7:
				effectiveness *= 0.5;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 0.5;
				break;
			case 11:
				effectiveness *= 2;
				break;
			case 12:
				effectiveness *= 0.5;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 0.5;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 13:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 2;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 0;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 1;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 2;
				break;
			case 12:
				effectiveness *= 0.5;
				break;
			case 13:
				effectiveness *= 0.5;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 0.5;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 14:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 2;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 2;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 0.5;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 0;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 15:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 2;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 2;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 0.5;
				break;
			case 11:
				effectiveness *= 0.5;
				break;
			case 12:
				effectiveness *= 2;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 0.5;
				break;
			case 16:
				effectiveness *= 2;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		case 16:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 1;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 2;
				break;
			case 17:
				effectiveness *= 1;
				break;
			case 18:
				effectiveness *= 0;
				break;
			}
			break;
		case 17:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 0.5;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 1;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 2;
				break;
			case 9:
				effectiveness *= 1;
				break;
			case 10:
				effectiveness *= 1;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 2;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 1;
				break;
			case 17:
				effectiveness *= 0.5;
				break;
			case 18:
				effectiveness *= 0.5;
				break;
			}
			break;
		case 18:
			switch (defendingType2) {
			case 1:
				effectiveness *= 1;
				break;
			case 2:
				effectiveness *= 2;
				break;
			case 3:
				effectiveness *= 1;
				break;
			case 4:
				effectiveness *= 0.5;
				break;
			case 5:
				effectiveness *= 1;
				break;
			case 6:
				effectiveness *= 1;
				break;
			case 7:
				effectiveness *= 1;
				break;
			case 8:
				effectiveness *= 1;
				break;
			case 9:
				effectiveness *= 0.5;
				break;
			case 10:
				effectiveness *= 0.5;
				break;
			case 11:
				effectiveness *= 1;
				break;
			case 12:
				effectiveness *= 1;
				break;
			case 13:
				effectiveness *= 1;
				break;
			case 14:
				effectiveness *= 1;
				break;
			case 15:
				effectiveness *= 1;
				break;
			case 16:
				effectiveness *= 2;
				break;
			case 17:
				effectiveness *= 2;
				break;
			case 18:
				effectiveness *= 1;
				break;
			}
			break;
		}
	}
	return effectiveness;
}

int partition(std::vector<pokemonSeed> &arr, int low, int high) {
	int pivot = arr.at(high).GetWin();

	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr.at(j).GetWin() < pivot) {
			i++;
			pokemonSeed temp = arr.at(i);
			arr.at(i) = arr.at(j);
			arr.at(j) = temp;
		}
	}

	pokemonSeed temp = arr.at(i + 1);
	arr.at(i + 1) = arr.at(high);
	arr.at(high) = temp;

	return (i + 1);
}
void quickSort(std::vector<pokemonSeed> &arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}