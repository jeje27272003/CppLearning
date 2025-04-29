//Dice.h  
#pragma once  
#include <random>  
#include <vector>  
#include <numeric> // std::accumulate  

struct RollResult {  
	std::vector<int> rolls; // 骰子結果  
	int total() const {  
		return std::accumulate(rolls.begin(), rolls.end(), 0); // 計算總和  
	}
};

inline RollResult rollDice(std::size_t n, int faces, std::mt19937& rng) {
	std::uniform_int_distribution<int> dist(1, faces);
	RollResult result;
	result.rolls.reserve(n); // 預留空間以提高性能  
	for (std::size_t i = 0; i < n; ++i) {
		result.rolls.push_back(dist(rng));
	}
	return result;
}