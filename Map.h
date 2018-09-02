#include <iostream>

#include "Player.h"

#ifndef MAP_H_
#define MAP_H_

class Map {
public:
	virtual ~Map() { };
	virtual void printInstas(int index) = 0; // Prints out the instas
	virtual void printRounds(int playerNumber) = 0; // Prints out where you should be on what round
	virtual void displayFootnote() = 0; // Prints out extra details for round
};

class DeadEnd : public Map {
private:
	std::vector < std::vector <int> > insta;
	std::vector <Player> players;
	std::string footnote;
public:
	DeadEnd(); // Map constructor
	std::vector <int> returnInstas(int index); // Returns the instas depending on the first round it spawns
	void setFootnote(std::string s);

	// Overriding functions

	void printInstas(int index);
	void printRounds(int playerNumber);
	void displayFootnote();
};

class BadBlood : public Map {
private:
	std::vector < std::vector <int> > insta;
	std::vector <Player> players;
	std::string footnote;
public:
	BadBlood();
	std::vector <int> returnInstas(int index);
	void setFootnote(std::string s);

	// Overriding functions

	void printInstas(int index);
	void printRounds(int playerNumber);
	void displayFootnote();
};

#endif /* MAP_H_ */
