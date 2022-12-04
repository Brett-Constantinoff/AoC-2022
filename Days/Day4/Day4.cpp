#include "Day4.h"
#include <iostream>
#include <fstream>

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
	int32_t count = 0;
	Ranges r;
	for (std::string s : m_inputData) {
		GetRanges(s, r);
		if ((r.x1 <= r.x0 && r.y1 >= r.y0) || (r.x0 <= r.x1 && r.y0 >= r.y1))
			count++;
	}
	std::cout << count << std::endl;
}

void Day4::Question2()
{
	int32_t count = 0;
	Ranges r;
	for (std::string s : m_inputData) {
		GetRanges(s, r);
		if ((std::min({r.y0, r.y1}) - std::max({r.x0, r.x1}) + 1) > 0)
			count++;
	}
	std::cout << count << std::endl;
}

void Day4::GetRanges(std::string &s, struct Ranges& r)
{
	r.x0 = std::stoi(s.substr(0, s.find(',')).substr(0, s.substr(0, s.find(',')).find('-')));
	r.y0 = std::stoi(s.substr(0, s.find(',')).substr(s.substr(0, s.find(',')).find('-') + 1, s.substr(0, s.find(',')).size() - s.substr(0, s.find(',')).find('-')));
	r.x1 = std::stoi(s.substr(s.find(',') + 1, s.size() - s.find(',')).substr(0, s.substr(s.find(',') + 1, s.size() - s.find(',')).find('-')));
	r.y1 = std::stoi(s.substr(s.find(',') + 1, 
					s.size() - s.find(',')).substr(s.substr(s.find(',') + 1, s.size() - s.find(',')).find('-') + 1, 
					s.substr(s.find(',') + 1, s.size() - s.find(',')).size() - s.substr(s.find(',') + 1, s.size() - s.find(',')).find('-')));
}