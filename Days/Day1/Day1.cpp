#include "Day1.h"
#include <iostream>
#include <fstream>

Day1::Day1(const std::string& file)
{
	std::ifstream fileData{ file };
	std::string fileLine;

	while (std::getline(fileData, fileLine))
		std::cout << fileLine;
	std::cin.get();
}

Day1::~Day1()
{

}