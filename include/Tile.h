#pragma once
#include "Rect.h"
#include "Object.h"

namespace ccm
{
	class Tile
	{
	public:
		Tile();
		Tile(const Rect& pos);
		Tile(int x, int y, int w, int h);

		const Object& draw() const;

		void fill();
		void empty();

	private:
		Object m_object;
	};
}