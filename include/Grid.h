#pragma once

#include <SDL.h>
#include "Color.h"
#include "Rect.h"
#include "Object.h"
#include <vector>
#include <algorithm>
#include <utility>

namespace ccm
{
	class Grid
	{
	private:
		class Tile
		{
		public:
			Tile();
			Tile(const Rect& pos);
			Tile(int x, int y, int w, int h);

			Object draw() const;

			void fill();
			void empty();

		private:
			Rect m_position;
			bool m_isFilled;
		};
	public:
		Grid(const Rect& position, int columns, int rows);
		Grid(int x, int y, int w, int h, int columns, int rows);

		Tile& operator()(int x, int y);

		int getWidth();
		int getHeight();
		std::pair<int, int> getDimensions();

		std::vector<Object> draw() const;

	private:
		const int m_numColumns, m_numRows;
		Rect m_position;
		std::vector<Tile> m_tiles;
	};
}