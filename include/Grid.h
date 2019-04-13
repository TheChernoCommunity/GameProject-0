#pragma once
#pragma once

#include <SDL.h>
#include "Color.h"
#include "Rect.h"
#include "Object.h"
#include "Tile.h"
#include <vector>
#include <algorithm>
#include <utility>

namespace ccm
{
	class Grid
	{
	private:
		
	public:
		Grid(const Rect& position, int columns, int rows);
		Grid(int x, int y, int w, int h, int columns, int rows);

		Tile& getTile(int x, int y);
		const std::vector<Tile>& getTiles() const;

		int getWidth() const;
		int getHeight() const;
		std::pair<int, int> getDimensions() const;

		const Object& draw() const;

	private:
		const int m_numColumns, m_numRows;
		Object m_object;
		std::vector<Tile> m_tiles;
	};
}
