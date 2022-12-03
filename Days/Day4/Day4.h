#pragma once
#include <string>
#include <vector>

class Day4
{
public:
	Day4(const std::string& file);
	~Day4();

	void Question1();
	void Question2();


private:
	std::vector<std::string> m_inputData;

};