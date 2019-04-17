#pragma once

#include "TextureGenerator.h"

#include <SDL.h>
#include <stb_image.h>

#include <string_view>
#include <memory>
#include <functional>

namespace ccm
{
	class Texture
	{
	public:
		Texture(std::string_view textureSource);
		SDL_Texture* draw() const ;
		int width() const;
		int height() const;
	private:
		std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture*)>> m_texture;
		int m_width, m_height, m_pitch;
	};
}