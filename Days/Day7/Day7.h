#pragma once
#include <string>
#include <vector>

class Day7
{
public:
	Day7(const std::string& file);
	~Day7();

	void Question1();
	void Question2();

private:
	void BubbleUp(std::vector<int64_t>& path, int64_t& sum);
	std::vector<std::string> Tokenize(std::string& s);
	int64_t StringToNum(std::string& s);

private:
	std::vector<std::string> m_inputData;
	std::vector<int64_t> m_sizes;
};