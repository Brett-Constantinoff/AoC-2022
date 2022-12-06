#include "Day5.h"
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

Day5::Day5(const std::string& file)
{
	std::ifstream fileData{ file };
	std::string fileLine;
	if (!fileData.is_open()) 
		exit(EXIT_FAILURE);

	bool startInstructions = false;
	while (std::getline(fileData, fileLine))
	{	
		if (fileLine.size() == 0)
			startInstructions = true;
		if (startInstructions)
			m_instructions.push_back(fileLine);
		else
			m_stackData.push_back(fileLine);
	}
	m_stackData.pop_back();
	fileData.close();
	MakeStacks();
}

Day5::~Day5()
{
}

void Day5::Question1()
{
	for (std::string s : m_instructions) 
	{
		Instruction i = GetInstruction(s);
		MoveCrates(m_stacks, i, false);
	}
	PrintSolution(m_stacks);
}

void Day5::Question2()
{
	for (std::string s : m_instructions) 
	{
		Instruction i = GetInstruction(s);
		MoveCrates(m_stacks, i, true);
	}
	PrintSolution(m_stacks);
}

void Day5::MakeStacks()
{
	std::size_t max = 0;
	for (int32_t i = 0; i < STACKS; i++) 
	{
		std::string s;
		for(auto it = m_stackData.begin(); it != m_stackData.end(); it++) 
		{
			if ((*it)[i * 4 + 1] != ' ') 
				s += (*it)[i * 4 + 1];
		}
		m_stacks.push_back(s);
	}
}

Instruction Day5::GetInstruction(std::string &s) 
{
	Instruction i{};
	boost::tokenizer<> tokens(s);
	boost::tokenizer<>::iterator it = tokens.begin();

	for (const auto &t : tokens)
	{
		try
		{
			int32_t num = boost::lexical_cast<int32_t>(t);
			if (i.amount == -1)
				i.amount = num;
			else if (i.from == -1)
				i.from = num;
			else
				i.to = num;
		}
		catch(...){};
	}
	return i;
}

void Day5::MoveCrates(std::vector<std::string> &stacks, Instruction &i, bool preserveOrder)
{
	if (i.amount == -1 || i.from == -1 || i.to == -1)
		return;
	std::string moved = stacks[i.from - 1].substr(0, i.amount);
	if (!preserveOrder)
		moved.reserve();
	stacks[i.to - 1] = moved + stacks[i.to - 1];
	stacks[i.from - 1].erase(0, i.amount);
}

void Day5::PrintSolution(std::vector<std::string> &stacks)
{
	for (auto s : stacks)
	{
		std::cout << s[0];
	}
	std::cout << std::endl;
}