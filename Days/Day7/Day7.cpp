#include "Day7.h"
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

Day7::Day7(const std::string& file)
{
	std::ifstream fileData{ file };
	std::string fileLine;
	if (!fileData.is_open()) 
		exit(EXIT_FAILURE);
	while (std::getline(fileData, fileLine))
		m_inputData.push_back(fileLine);
}

Day7::~Day7()
{
}

void Day7::Question1()
{
	std::vector<int64_t> path;
	int64_t sum = 0;
	for (auto s : m_inputData)
	{
		auto tokens = Tokenize(s);
		int64_t size = StringToNum(tokens[0]);
		// record the current path size and add it to its parent
		if (tokens[1] == "cd" && tokens[2] == "..")
			BubbleUp(path, sum);
		// start of a new directory
		else if (tokens[1] == "cd" && tokens[2] != "..")
			path.push_back(0);
		// add to current directory
		else if (size != -1)
			path.back() += size;
	}
	// continue with whatever is left in the stack
	while (!std::empty(path))
		BubbleUp(path, sum);
	std::cout << sum << std::endl;
}

void Day7::Question2()
{
	int64_t min = 3e7;
	int64_t max = *std::max_element(m_sizes.begin(), m_sizes.end());
	for (const auto& i : m_sizes)
	{
		if (i >= (max - 4e7))
			min = std::min({min, i});
	}
	std::cout << min << std::endl;
}

void Day7::BubbleUp(std::vector<int64_t>& path, int64_t& sum)
{
	m_sizes.push_back(path.back());
	path.pop_back();
	if (!path.empty())
		path.back() += m_sizes.back();
	if (m_sizes.back() <= 1e5)
		sum += m_sizes.back();
}


std::vector<std::string> Day7::Tokenize(std::string& s)
{
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep{" "};
	tokenizer tokens{s, sep};
	std::vector<std::string> toReturn;
	for (auto it = tokens.begin(); it != tokens.end(); it++)
		toReturn.push_back(*it);
	return toReturn;
}

int64_t Day7::StringToNum(std::string& s)
{
	try {return boost::lexical_cast<int64_t>(s);}
	catch(...) {return -1;}
}