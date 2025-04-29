//Dice.h  
#pragma once  
#include <random>  
#include <vector>  
#include <numeric> // std::accumulate  

struct RollResult {  
	std::vector<int> rolls; // ��l���G  
	int total() const {  
		return std::accumulate(rolls.begin(), rolls.end(), 0); // �p���`�M  
	}
};

inline RollResult rollDice(std::size_t n, int faces, std::mt19937& rng) {
	std::uniform_int_distribution<int> dist(1, faces);
	RollResult result;
	result.rolls.reserve(n); // �w�d�Ŷ��H�����ʯ�  
	for (std::size_t i = 0; i < n; ++i) {
		result.rolls.push_back(dist(rng));
	}
	return result;
}