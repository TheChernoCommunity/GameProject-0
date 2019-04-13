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
		Rect rect;
		Color color;
	};
}
