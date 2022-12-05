#include "Day5.h"
#include <iostream>
#include <fstream>

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
	std::vector<std::stack<char>> stacks{m_stacks};
	for (std::string s : m_instructions) 
	{
		Instruction i = GetInstruction(s);
		MoveCrates(stacks, i, false);
	}
	PrintSolution(stacks);
}

void Day5::Question2()
{
	std::vector<std::stack<char>> stacks{m_stacks};
	for (std::string s : m_instructions) 
	{
		Instruction i = GetInstruction(s);
		MoveCrates(stacks, i, true);
	}
	PrintSolution(stacks);
}

void Day5::MakeStacks()
{
	for (int32_t i = 0; i < STACKS; i++) 
	{
		std::stack<char> s;
		for(auto it = m_stackData.rbegin(); it != m_stackData.rend(); it++) 
		{
			if ((*it)[i * 4 + 1] != ' ') 
				s.push((*it)[i * 4 + 1]);
		}
		m_stacks.push_back(s);
	}
}

Instruction Day5::GetInstruction(std::string &s) 
{
	Instruction i{};
	std::stringstream ss{s};
	std::string temp{};
	int32_t num{};
	while (!ss.eof()) 
	{
		ss >> temp;
		if (std::stringstream{temp} >> num) 
		{
			if (i.amount == -1) i
				.amount = num;
			else if (i.from == -1) 
				i.from = num;
			else if (i.to == -1) 
				i.to = num;
		}
	}
	return i;
}

void Day5::MoveCrates(std::vector<std::stack<char>> &stacks, Instruction &i, bool preserveOrder)
{
		std::vector<char> temp;
		for (int32_t amount = 0; amount < i.amount; amount++)
		{
			temp.push_back(stacks[i.from - 1].top());
			stacks[i.from - 1].pop();
		}
		if (preserveOrder)
		{
			for (auto it = temp.rbegin(); it != temp.rend(); it++) 
				stacks[i.to - 1].push(*it);
		}
		else
		{
			for (auto it = temp.begin(); it != temp.end(); it++) 
				stacks[i.to - 1].push(*it);
		}		
}

void Day5::PrintSolution(std::vector<std::stack<char>> &stacks)
{
	for (int32_t i = 0; i < STACKS; i++) 
		std::cout << stacks[i].top();
	std::cout << std::endl;
}