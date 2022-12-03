#include "Day4.h"
#include <iostream>

Day4::Day4(const std::string& file)
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

Day4::~Day4()
{

}

void Day4::Question1()
{
}

void Day4::Question2()
{
}