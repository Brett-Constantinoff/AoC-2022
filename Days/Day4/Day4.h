#pragma once
#include <string>
#include <vector>

struct Ranges
{
	int32_t x0, y0;
	int32_t x1, y1;
};

class Day4
{
public:
	Day4(const std::string& file);
	~Day4();

	void Question1();
	void Question2();

private:
	void GetRanges(std::string& s, struct Ranges& r);

private:
	std::vector<std::string> m_inputData;

};