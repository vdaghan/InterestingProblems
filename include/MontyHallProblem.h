// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once

#include <algorithm>
#include <random>
#include <vector>

using GameState = std::vector<size_t>;

size_t pickRandom(GameState const & gameState) {
	static std::random_device r;
	static std::default_random_engine randGen(r());
	std::uniform_int_distribution<size_t> distribution(0, gameState.size()-1);
	size_t index = distribution(randGen);
	return gameState[index];
}

enum class Winner {Stay, Switch};
struct Game {
	size_t prizeDoor;
	size_t picked;
	size_t reveal;
	Winner winner;
};

Game play() {
	Game game;
	GameState gameState({ 0,1,2 });
	game.prizeDoor = pickRandom(gameState);
	game.picked = pickRandom(gameState);
	GameState revealable(2);
	std::remove_copy(gameState.begin(), gameState.end(), revealable.begin(), game.picked);
	game.reveal = pickRandom(revealable);
	if (game.prizeDoor == game.picked) {
		game.winner = Winner::Stay;
	} else {
		game.winner = Winner::Switch;
	}
	return game;
}
