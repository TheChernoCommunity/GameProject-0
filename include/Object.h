#pragma once

#include "Rect.h"
#include "Color.h"
#include "Texture.h"
#include <variant>
namespace ccm
{
	/*
	 * General Renderable objects that contain information about
	 * its drawing information, transform, collision information,
	 * etc...
	 */
	class Object
	{
	public:
		Object() = default;
		Object(const Rect& r, const std::variant<Color, const Texture*>& c)
			: rect(r), apperance(c)
		{}
		Object(const Rect& r, const Texture& c)
			: Object(r, &c)
		{}
		void bindTexture(const Texture& tex)
		{
			apperance = &tex;
		}
		void setColor(const Color& c)
		{
			apperance = c;
		}

		Rect rect;
		std::variant<Color, const Texture*> apperance;
	};
}
