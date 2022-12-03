#include "Day1.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Day1::Day1(const std::string& file)
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

	GetCalPerElf();
}

Day1::~Day1()
{

}

void Day1::Question1()
{
	std::cout << "Question 1: " << m_calPerElf[m_calPerElf.size() - 1] << std::endl;
}

void Day1::Question2()
{
	std::cout << "Question 2: " <<  m_calPerElf[m_calPerElf.size() - 1] +
				 					m_calPerElf[m_calPerElf.size() - 2] +
				 					m_calPerElf[m_calPerElf.size() - 3] << std::endl;
}

void Day1::GetCalPerElf()
{
	int32_t currCalories = 0;
	for (std::string calories : m_inputData)
	{
		if (calories.size() != 0) 
		{
			currCalories += std::stoi(calories);
		}
		else
		{
			m_calPerElf.push_back(currCalories);
			currCalories = 0;
		}
	}
	std::sort(m_calPerElf.begin(), m_calPerElf.end());
}