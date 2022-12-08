#pragma once
#include <string>
#include <vector>

class Day8
{
public:
	Day8(const std::string& file);
	~Day8();

	void Question1();
	void Question2();

private:
	bool CheckVisible(char i, char j, int32_t& view);
	bool VisibleAbove(int32_t index, int32_t& view);
	bool VisibleBelow(int32_t index, int32_t& view);
	bool VisibleRight(int32_t index, int32_t& view);
	bool VisibleLeft(int32_t index, int32_t& view);

private:
	std::string m_inputData;
	int32_t m_visible{};
	int32_t m_maxView{};
	int32_t m_rows{-1};
	int32_t m_coloumns{-1};
};