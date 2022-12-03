#pragma once
#include <string>
#include <vector>

class Day3
{
public:
	Day3(const std::string& file);
	~Day3();

	void Question1();
	void Question2();


private:
	std::vector<std::string> m_inputData;

};