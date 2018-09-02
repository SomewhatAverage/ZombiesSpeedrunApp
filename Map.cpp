#include "Map.h"

DeadEnd::DeadEnd() {
	setFootnote("Purchase sniper ammo every round from 22 - 25.\nThe closest player to the TM should buy ammo every round after 26.");

	insta.resize(2); // Creates room for two types of insta waves
	insta[0].insert(insta[0].end(), {2, 8, 11, 14, 17, 23});
	insta[1].insert(insta[1].end(), {3, 6, 9, 12, 18, 21, 24});

	players.resize(4); // Creates room for 4 players
	for (int i = 0; i < 4; i++) {
		players[i].rounds.resize(3); // 3 stages of areas to go
	}

	std::vector < std::vector <roundPair> > playerList = {
			{
				roundPair(10, "alley"), roundPair(21, "apartments"), roundPair(26, "alley")
			},
			{
				roundPair(10, "alley"), roundPair(21, "hotel"), roundPair(26, "power")
			},
			{
				roundPair(10, "office"), roundPair(21, "alley"), roundPair(26, "apartments")
			},
			{
				roundPair(10, "office"), roundPair(21, "office"), roundPair(26, "hotel")
			}
	};

	for (int i = 0; i < 4; i++) {
		players[i].rounds = playerList[i]; // Match up class data to constructor data
	}
}

std::vector <int> DeadEnd::returnInstas(int index) {
	return insta[index]; // Returns the insta for either the 2 round or the 3 round
}

void DeadEnd::setFootnote(std::string s) {
	footnote = s;
}

void DeadEnd::printInstas(int index) {
	std::vector <int> instas = returnInstas(index);
	std::cout << "The instas will spawn on ";

	for (int i = 0; i < (int)instas.size() - 1; i++) { // Grammatical ending
		std::cout << instas[i] << ", ";
	}

	std::cout << "and " << instas[instas.size()-1] << "." << std::endl;
}

void DeadEnd::printRounds(int playerNumber) {
	for (int i = 0; i < (int)players[playerNumber].rounds.size(); i++) {
		std::cout << "On round " << players[playerNumber].rounds[i].first;
		std::cout << ", you should be in " << players[playerNumber].rounds[i].second << "." << std::endl;
	}
}

void DeadEnd::displayFootnote() {
	std::cout << footnote << std::endl;
}

BadBlood::BadBlood() {
	setFootnote("Buy sniper ammo even if you do not need it.\nOn round 22, switch with the player 2 numbers away from you and buy perks.");

	insta.resize(2);
	insta[0].insert(insta[0].end(), {2, 5, 8, 11, 14, 17, 23, 26});
	insta[1].insert(insta[1].end(), {3, 6, 9, 12, 18, 21, 24, 27});

	players.resize(4);
	for (int i = 0; i < 4; i++) {
		players[i].rounds.resize(4); // 4 stages this time
	}

	std::vector < std::vector <roundPair> > playerList = {
		{
			roundPair(10, "courtyard"), roundPair(21, "great hall"), roundPair(26, "library"), roundPair(22, "great hall")
		},
		{
			roundPair(10, "mansion"), roundPair(21, "mansion"), roundPair(26, "dungeon"), roundPair(22, "mansion")
		},
		{
			roundPair(10, "library room 1"), roundPair(21, "library"), roundPair(26, "great hall"), roundPair(22, "library")
		},
		{
			roundPair(10, "library room 2"), roundPair(21, "dungeon"), roundPair(26, "mansion"), roundPair(22, "dungeon")
		}
	};

	for (int i = 0; i < 4; i++) {
		players[i].rounds = playerList[i];
	}
}

std::vector <int> BadBlood::returnInstas(int index) {
	return insta[index];
}

void BadBlood::setFootnote(std::string s) {
	footnote = s;
}

void BadBlood::printInstas(int index) {
	std::vector <int> instas = returnInstas(index);
	std::cout << "The instas will spawn on ";
	for (int i = 0; i < (int)instas.size() - 1; i++) { // Grammatical ending
		std::cout << instas[i] << ", ";
	}

	std::cout << "and " << instas[instas.size()-1] << "." << std::endl;
}

void BadBlood::printRounds(int playerNumber) {
	for (int i = 0; i < (int)players[playerNumber].rounds.size(); i++) {
		std::cout << "On round " << players[playerNumber].rounds[i].first;
		std::cout << ", you should be in " << players[playerNumber].rounds[i].second << "." << std::endl;
	}
}

void BadBlood::displayFootnote() {
	std::cout << footnote << std::endl;
}
