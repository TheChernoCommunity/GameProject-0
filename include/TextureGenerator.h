#pragma once

#include "SDL.h"
#include "stb_image.h"

#include <string_view>
#include <assert.h>
#include <tuple>
namespace ccm
{
	class Renderer;
	class TextureGenerator
	{
	public:

		/*
		* Creates an instantiation of the singleton
		* @Param renderer: reference to the render to use to generate SDL_Textures
		*/
		static void create(Renderer& r);

		/*
		* Generates an SDL texture from a file
		* @param Texture Source: the image file to be loaded
		* @return: A pointer to the loaded SDL_texture, the width, height, and pitch of the loaded image
		*/
		static std::tuple<SDL_Texture*, int, int, int> loadTextureFromFile(std::string_view textureSource);
	private:
		inline static Renderer* m_renderer;
	};
}