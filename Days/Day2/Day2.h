#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "../Common.h"

enum Result
{
	WIN = 6,
	DRAW = 3,
};

class Day2
{
public:
	Day2(const std::string& file);
	~Day2();

	void Question1();
	void Question2();

private:
	std::vector<std::string> m_inputData;
	std::unordered_map<char, char> m_wins = {
		{'X', 'C'},
		{'Z', 'B'},
		{'Y', 'A'}
	};
	std::unordered_map<char, char> m_draws = {
		{'X', 'A'},
		{'Z', 'C'},
		{'Y', 'B'},

		{'A', 'X'},
		{'C', 'Z'},
		{'B', 'Y'}
	};
	std::unordered_map<char, char> m_losses = {
		{'B', 'X'},
		{'A', 'Z'},
		{'C', 'Y'}
	};
	std::unordered_map<char, int32_t> m_choiceScore = {
		{'X', 1},
		{'Y', 2},
		{'Z', 3}
	};
};
