#include "Day8.h"
#include <iostream>
#include <fstream>

Day8::Day8(const std::string& file)
{
	std::ifstream fileData{ file };
	std::string fileLine{};
	if (!fileData.is_open()) 
		exit(EXIT_FAILURE);
	int32_t rows{0};
	while (std::getline(fileData, fileLine))
	{
		m_inputData += fileLine;
		if (m_coloumns == -1)
			m_coloumns = fileLine.length();
		rows++;
	}
	m_rows{rows};
}

Day8::~Day8()
{
}

void Day8::Question1()
{
	for (int32_t i{0}; i < m_inputData.length(); i++)
	{
		int32_t up{}, down{}, left{}, right{};
		bool visible{false};
		bool edge = i <= m_rows - 1 	|| i >= m_inputData.length() - m_rows ||
			    i % m_coloumns == 0 || i % m_coloumns == m_coloumns - 1;
		if (edge) m_visible++;
		else
		{
			if (VisibleAbove(i, up)) visible = true;
			if (VisibleBelow(i, down)) visible = true;
			if (VisibleLeft(i, left)) visible = true;
			if (VisibleRight(i, right)) visible = true;
			if (visible) m_visible++;
			
			int32_t max{1};
			if (up > 0) max *= up;
			if (down > 0) max *= down;
			if (left > 0) max *= left;
			if (right > 0) max *= right;
			m_maxView = std::max({max, m_maxView});
		}
	}
	std::cout << m_visible << std::endl;
}

void Day8::Question2()
{
	std::cout << m_maxView << std::endl;
}

bool Day8::CheckVisible(char i, char j, int32_t& view)
{
		view++;
		if (static_cast<int32_t>(i) >= static_cast<int32_t>(j))
			return false;
		return true;
}

bool Day8::VisibleAbove(int32_t index, int32_t& view)
{
	int64_t i{index};
	i -= m_rows;
	while (i > 0)
	{
		if (!CheckVisible(m_inputData[i], m_inputData[index], view))
			return false;
		i -= m_rows;
	}
	return true;
}

bool Day8::VisibleBelow(int32_t index, int32_t& view)
{
	int64_t i{index};
	i += m_rows;
	while (i < m_inputData.size())
	{
		if (!CheckVisible(m_inputData[i], m_inputData[index], view))
			return false;
		i += m_rows;
	}
	return true;
}

bool Day8::VisibleRight(int32_t index, int32_t& view)
{
	int64_t i{index};
	while (i++ % m_coloumns != m_coloumns - 1)
	{
		if (!CheckVisible(m_inputData[i], m_inputData[index], view))
			return false;
	}
	return true;
}

bool Day8::VisibleLeft(int32_t index, int32_t& view)
{
	int64_t i{index};
	while (i-- % m_coloumns != 0)
	{
		if (!CheckVisible(m_inputData[i], m_inputData[index], view))
			return false;
	}
	return true;
}
