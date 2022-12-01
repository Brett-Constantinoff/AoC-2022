#pragma once
#include <string>
#include <vector>
#include "../Common.h"

class Day1
{
public:
	Day1(const std::string& file);
	virtual ~Day1();

	virtual void Question1();
	virtual void Question2();

private:
	void GetCalPerElf();
private:
	std::vector<std::string> m_inputData;
	std::vector<int32_t> m_calPerElf;
};