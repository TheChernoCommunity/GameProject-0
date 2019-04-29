#pragma once

#include "TextureGenerator.h"

#include <SDL.h>
#include <stb_image.h>

#include <string_view>
#include <memory>
#include <functional>
#include <utility>

namespace ccm
{
	class Texture
	{
	private:
		struct TextureDeleter
		{
			void operator()(SDL_Texture* texture);
		};
	public:
		Texture() = default;
		Texture(std::string_view textureSource);

		Texture(const Texture& other) = delete;
		Texture(Texture&& other) = default;
		Texture& operator=(const Texture& other) = delete;
		Texture& operator=(Texture&& other) = default;
		~Texture() = default;
				
		/* Returns the underlying texture so the render can draw to the screen. */
		SDL_Texture& draw() const ;
		/* Returns the width of the loaded texture */
		int getWidth() const;
		/* Returns the height of the loaded texture */
		int getHeight() const;
		/* Returns the dimensions of the loaded texture */
		std::pair<int, int> getDimensions() const;
	private:
		std::unique_ptr<SDL_Texture, TextureDeleter> m_texture;
		int m_width, m_height, m_pitch;
	};
}