#include <vector>
#include <string>

typedef std::pair<int, std::string> roundPair; // Shorten for ease of reading

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
	std::vector <roundPair> rounds;
};

#endif /* PLAYER_H_ */
