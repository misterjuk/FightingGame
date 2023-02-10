#pragma once

#include <iostream>
#include <string>
#include "utils.h"

using namespace utils;

class Sprite
{

public:

	Texture m_Texture{};
	Point2f m_CellSize{};
	int m_Rows{};
	int m_Columns{};

	void Load(const std::string& fileLocation, int column = { 1 }, int row = { 1 })
	{
		m_Rows = std::max(1, row);
		m_Columns = std::max(1, column);


		TextureFromFile(fileLocation, m_Texture);
		m_CellSize.x = m_Texture.width / m_Columns;
		m_CellSize.y = m_Texture.height / m_Rows;

		std::cout << "Texture Loaded: " << fileLocation << std::endl;
	}

	~Sprite()
	{
		DeleteTexture(m_Texture);
		std::cout << "Texture Deleted" << std::endl;
	}

	void Draw(const Rectf& drawRect)
	{
		DrawTexture(m_Texture, drawRect);
	}

	void Draw(const Rectf& drawRect, int column, int row = {})
	{
		DrawTexture(m_Texture, drawRect,{ m_CellSize.x * column,m_CellSize.y * (row + 1),m_CellSize.x,m_CellSize.y});
	}

	void Draw(const Point2f& drawPosition, int column, int row = {})
	{
		DrawTexture(m_Texture, drawPosition, { m_CellSize.x * column,m_CellSize.y * (row + 1),m_CellSize.x,m_CellSize.y });
	}

	void Draw(const Point2f& drawPosition)
	{
		DrawTexture(m_Texture, drawPosition);
	}

};

