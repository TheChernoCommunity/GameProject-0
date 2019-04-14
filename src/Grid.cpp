#include "Grid.h"
#include <iterator>

namespace ccm
{
	// Grid Method Implementations
	Grid::Grid(int x, int y, int w, int h, int columns, int rows)
		: Grid(Rect{ x, y, w, h }, columns, rows)
	{

	}

	Grid::Grid(const Rect& position, int columns, int rows)
		: m_object(position, Color(128, 128, 128, 255)), m_numColumns(columns), m_numRows(rows)
	{
		int tileWidth = m_object.rect.rect.w / columns;
		int tileHeigh = m_object.rect.rect.h / rows;

		m_tiles.reserve(columns * rows);
		for (int y = 0; y < m_numRows; ++y)
			for (int x = 0; x < m_numColumns; ++x)
				m_tiles.emplace_back(x * tileWidth + 1 + position.rect.x, y * tileHeigh + 1 + position.rect.y, tileWidth - 2, tileHeigh - 2);
	}

	Tile& Grid::getTile(int x, int y)
	{
		return m_tiles[y * m_numColumns + x];
	}

	const std::vector<Tile>& Grid::getTiles() const
	{
		return m_tiles;
	}

	int Grid::getWidth() const
	{
		return m_numColumns;
	}

	int Grid::getHeight() const
	{
		return m_numRows;
	}
	 
	std::pair<int, int> Grid::getDimensions() const
	{
		return std::make_pair(m_numColumns, m_numRows);
	}

	const Object& Grid::draw() const
	{
		return m_object;
	}
}
