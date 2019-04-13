#pragma once

#include "Rect.h"
#include "Color.h"

namespace ccm
{
	/*
	 * General Renderable objects that contain information about
	 * its drawing information, transform, collision information,
	 * etc...
	 */
	struct Object
	{
		Object() = default;
		Object(const Rect& r, const Color& c)
			: rect(r), color(c)
		{}
		Rect rect;
		Color color;
	};
}
