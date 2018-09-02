#include "Map.h"

int main() {
	Map* map; // Map pointer to adjust for either BB or DE

	int playerNumber;
	int instaRound;
	std::string mapName; // These should be self explanatory

	std::cout << "What player number are you?" << std::endl;
	std::cin >> playerNumber;
	while (std::cin.fail() || playerNumber < 1 || playerNumber > 4) {
		std::cin.clear();
		std::cin.ignore(256, '\n'); // Allows cin to be read again

		std::cout << "Please enter a valid integer from 1 - 4!" << std::endl;
		std::cin >> playerNumber;
	}

	std::cin.ignore(256, '\n'); // Clears newline so getline awaits response

	std::cout << "Which map are you playing?" << std::endl;
	getline(std::cin, mapName); // getline should be used instead of cin with a string
	while ((mapName != "Dead End") && (mapName != "Bad Blood")) {
		std::cout << "Please enter a valid map! (Dead End or Bad Blood)" << std::endl;
		getline(std::cin, mapName);
	}

	std::cout << "What round did the insta-kill first spawn?" << std::endl;
	std::cin >> instaRound;
	while (std::cin.fail() || ((instaRound != 2) && (instaRound != 3))) {
		std::cin.clear();
		std::cin.ignore(256, '\n');

		std::cout << "Please enter either 2 or 3!" << std::endl;
		std::cin >> instaRound;
	}

	(mapName == "Dead End") ? map = new DeadEnd : map = new BadBlood; // Allocates type of object for map
	map->printInstas(instaRound - 2); // Prints insta rounds
	map->printRounds(playerNumber); // Print round info per player
	map->displayFootnote(); // Displays footnote for each map
	delete map; // No memory leak

	bool keepAlive = true;
	std::string input;

	std::cout << "Type \"QUIT\" to quit." << std::endl;
	while (keepAlive) {
		getline(std::cin, input); // Ignoring spaces
		if (input == "QUIT") { keepAlive = false; } // Until the user enters quit, the program will remain alive.
	}


	return 0;
}
