#include "Day6.h"
#include <iostream>
#include <fstream>
#include <map>

Day6::Day6(const std::string& file)
{
	std::ifstream fileData{ file };
	std::string fileLine;
	if (!fileData.is_open()) 
		exit(EXIT_FAILURE);
	std::getline(fileData, m_inputData);
}

Day6::~Day6()
{
}

void Day6::Question1()
{
	FindMarker(4);
}

void Day6::Question2()
{
	FindMarker(14);
}

void Day6::FindMarker(const int32_t windowSize)
{
	for (int32_t i = 0; i < m_inputData.length(); i++)
	{
		std::string window = m_inputData.substr(i, windowSize);
		if (Scan(window))
		{
			std::cout << i + windowSize << std::endl;
			break;
		}
	}
}

bool Day6::Scan(std::string &sub)
{
	int32_t check = 0;
	for (int32_t i = 0; i < sub.length(); i++)
	{
		int32_t bit = sub[i] - 'a';
		if ((check & (1 << bit)) > 0)
			return false;
		check = check | (1 << bit);
	}
	return true;
}