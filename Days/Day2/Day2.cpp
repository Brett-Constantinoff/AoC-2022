#include "Day2.h"
#include <iostream>
#include <fstream>

Day2::Day2(const std::string& file)
{
	std::ifstream fileData{ file };
	std::string fileLine;
	if (!fileData.is_open())
	{
		std::cout << "Cannot find file: " << file << std::endl;
		exit(EXIT_FAILURE);
	}
	while (std::getline(fileData, fileLine))
		m_inputData.push_back(fileLine);
	fileData.close();
}

Day2::~Day2()
{

}

void Day2::Question1()
{
	int32_t score = 0;
	for (std::string s : m_inputData) 
	{
		char myChoice = s[2];
		char oppChoice = s[0];
		auto winsIt = m_wins.find(myChoice);
		auto drawsIt = m_draws.find(myChoice);
		auto scoreIt = m_choiceScore.find(myChoice);
		score += scoreIt->second;

		if (winsIt != m_wins.end() && oppChoice == winsIt->second)
			score += Result::WIN;
		else if (drawsIt != m_draws.end() && oppChoice == drawsIt->second)
			score += Result::DRAW;
	}
	std::cout << score << std::endl;
}

void Day2::Question2()
{
	int32_t score = 0;
	for (std::string s : m_inputData) 
	{
		char myChoice;
		char oppChoice = s[0];
		char result = s[2];
		if (result == 'Y') 
		{
			score += Result::DRAW;
			myChoice = m_draws.find(oppChoice)->second;
		} 
		else if (result == 'X') 
		{
			myChoice = m_losses.find(oppChoice)->second;
		} 
		else 
		{
			score += Result::WIN;
			for (auto &it : m_wins) 
			{
				if (it.second == oppChoice)
					myChoice = it.first;
			}	
		}
		score += m_choiceScore.find(myChoice)->second;
	}
	std::cout << score << std::endl;
}