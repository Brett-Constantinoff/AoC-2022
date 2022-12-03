#include "Day3.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

Day3::Day3(const std::string& file)
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

Day3::~Day3()
{

}

void Day3::Question1()
{
	int32_t total = 0;
	for (std::string s : m_inputData) {
		size_t half = s.size() / 2;
		for (size_t i = 0; i < s.size(); i++) {
			if (std::count(s.begin() + half, s.end(), s[i])) {
				int32_t priority = islower(s[i]) ? 1 + ((26 - 1) / ('z' - 'a')) * (s[i] - 'a') :
								   27 + ((52 - 27) / ('Z' - 'A')) * (s[i] - 'A');
				total += priority;
				break;
			}
		}
	}
	std::cout << total << std::endl;
}

void Day3::Question2()
{
	int32_t total = 0;
	for (size_t i = 0; i < m_inputData.size(); i += 3) {
		for (size_t j = 0; j < m_inputData[i].size(); j++) {
			int64_t a = std::count(m_inputData[i + 1].begin(), m_inputData[i + 1].end(), m_inputData[i][j]);
			int64_t b = std::count(m_inputData[i + 2].begin(), m_inputData[i + 2].end(), m_inputData[i][j]);
			if (a && b) {
				int32_t priority = islower(m_inputData[i][j]) ? 1 + ((26 - 1) / ('z' - 'a')) * (m_inputData[i][j] - 'a') :
							       27 + ((52 - 27) / ('Z' - 'A')) * (m_inputData[i][j] - 'A');
				total += priority;
				break;
			}
		}
	}
	std::cout << total << std::endl;
}