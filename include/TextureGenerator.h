#pragma once

#include "SDL.h"
#include "stb_image.h"
#include "Singleton.h"
#include <string_view>
#include <assert.h>
#include <tuple>
namespace ccm
{
	class Renderer;
	class TextureGenerator : public Singleton<TextureGenerator>
	{
	private:
		struct TextureInfo { SDL_Texture* tex; int width, height, pitch; };
	public:
		TextureGenerator(Renderer&);
		/*
		* Generates an SDL texture from a file
		* @param Texture Source: the image file to be loaded
		* @return: A pointer to the loaded SDL_texture, the width, height, and pitch of the loaded image
		*/
		TextureInfo loadTextureFromFile(std::string_view textureSource);
	private:
		inline static Renderer* m_renderer;
	};
}