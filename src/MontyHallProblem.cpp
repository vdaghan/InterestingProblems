// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "MontyHallProblem.h"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t const numSimulations(1000000);

	std::vector<Winner> winners(numSimulations);
	for (size_t i(0); i != numSimulations; ++i) {
		Game game = play();
		winners[i] = game.winner;
	}

	size_t switcherWins = std::count(winners.begin(), winners.end(), Winner::Switch);
	size_t stayerWins = std::count(winners.begin(), winners.end(), Winner::Stay);
	
	std::cout << "Over " << numSimulations << " simulations, "
		<< "switcher won " << switcherWins << " times whereas "
		<< "stayer won " << stayerWins << " times."
		<< std::endl;
	return 0;
}
