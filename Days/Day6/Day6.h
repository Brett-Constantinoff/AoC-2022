#pragma once
#include <string>
#include <vector>
#include <stack>
#include <sstream>

class Day6
{
public:
	Day6(const std::string& file);
	~Day6();

	void Question1();
	void Question2();

private:
	void FindMarker(const int32_t windowSize);
	bool Scan(std::string &sub);
private:
	std::string m_inputData;
};