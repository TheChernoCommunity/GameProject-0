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
		: m_position(position), m_numColumns(columns), m_numRows(rows)
	{
		int tileWidth = m_position.rect.w / columns;
		int tileHeigh = m_position.rect.h / rows;

		m_tiles.reserve(columns * rows);
		for (int y = 0; y < m_numRows; ++y)
			for (int x = 0; x < m_numColumns; ++x)
				m_tiles.emplace_back(x * tileWidth + 1 + position.rect.x, y * tileHeigh + 1 + position.rect.y, tileWidth - 2, tileHeigh - 2);
	}

	Grid::Tile& Grid::operator()(int x, int y)
	{
		return m_tiles[y * m_numColumns + x];
	}

	int Grid::getWidth()
	{
		return m_numColumns;
	}

	int Grid::getHeight()
	{
		return m_numRows;
	}

	std::pair<int, int> Grid::getDimensions()
	{
		return std::make_pair(m_numColumns, m_numRows);
	}

	std::vector<Object> Grid::draw() const
	{
		std::vector<Object> retVal;
		retVal.reserve(m_numColumns * m_numRows + 1);
		retVal.emplace_back(m_position, Color(128, 128, 128, 255));
		std::transform(
			m_tiles.begin(), m_tiles.end(),
			std::back_inserter(retVal), [](const Tile& tile)
			{
				return tile.draw();
			}
		);
		return retVal;
	}

	// Tile Method Implementations

	Grid::Tile::Tile(const Rect& pos)
		: m_position(pos), m_isFilled(false)
	{	}

	Grid::Tile::Tile(int x, int y, int w, int h)
		: Tile(Rect{ x, y, w, h })
	{	}

	Grid::Tile::Tile() = default;

	Object Grid::Tile::draw() const
	{
		return { m_position, m_isFilled ? Colors::Green : Colors::Red };
	}

	void Grid::Tile::fill()
	{
		m_isFilled = true;
	}

	void Grid::Tile::empty()
	{
		m_isFilled = false;
	}

}
