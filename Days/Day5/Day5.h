#pragma once
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#define STACKS 9

struct Instruction
{
	int32_t amount{-1}, to{-1}, from{-1};
};

class Day5
{
public:
	Day5(const std::string& file);
	~Day5();

	void Question1();
	void Question2();

private:
	void MakeStacks();
	Instruction GetInstruction(std::string &s);
	void MoveCrates(std::vector<std::stack<char>> &stacks, Instruction &i, bool preserveOrder);
	void PrintSolution(std::vector<std::stack<char>> &stacks);

private:
	std::vector<std::string> m_stackData;
	std::vector<std::string> m_instructions;
	std::vector<std::string> m_inputData;
	std::vector<std::stack<char>> m_stacks;
};
