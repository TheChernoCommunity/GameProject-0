#pragma once

#include "Renderer.h"
#include "SDL.h"
#include "stb_image.h"

#include <string_view>
#include <assert.h>
#include <tuple>

namespace ccm
{
	class TextureGenerator
	{
	public:
		static void create(Renderer& r);
		static std::tuple<SDL_Texture*, int, int, int> loadTextureFromFile(std::string_view textureSource);
	private:
		inline static Renderer* m_renderer;
	};
}