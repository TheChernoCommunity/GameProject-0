#pragma once

#include <memory>
#include "Application.h"
#include "Object.h"
#include "Rect.h"
#include "Texture.h"
#include "Util.h"

namespace ccm
{
	/*
	* Renderer class.
	* Clears, paints, and renders renderable objects
	*/
	class Renderer
	{
	public:
		Renderer(Application&);
		/*
		 * Clears the drawing buffer. Called before drawing objects.
		 */
		void clear();

		/*
		 * Paints renderable objects onto the buffer.
		 * @param object: object to be drawn
		 */
		void draw(const Object& obj);

		SDL_Texture* createTextureFromSurface(SDL_Surface* src);

		void renderTexture(const Texture& source, const Rect& dest);

		void renderSurface(SDL_Surface* source, const Rect dest);

		/*
		 * Renders all drawn objects to the screen.
		 */
		void render();
	private:
		SDL_Renderer* m_renderer{ nullptr };
		/*
		 * Sets the color mode for the Renderer
		 * @param color : color used for renderer color mode
		 */
		void setRenderColor(const Color& color);

		/*
		 * Fills a rect with the current drawing color
		 * @param rect : rect to be filled with drawing color
		 */
		void fillRect(const Rect& rect);
	};
}
