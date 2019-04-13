#include "Tile.h"

namespace ccm
{
	Tile::Tile(const Rect& pos)
		: m_object(pos, Colors::Red)
	{	}

	Tile::Tile(int x, int y, int w, int h)
		: Tile(Rect{ x, y, w, h })
	{	}

	Tile::Tile() = default;

	const Object& Tile::draw() const
	{
		return m_object;
	}

	void Tile::fill()
	{
		m_object.color = Colors::Green;
	}

	void Tile::empty()
	{
		m_object.color = Colors::Green;
	}
}