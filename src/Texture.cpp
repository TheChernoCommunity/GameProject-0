#include "Texture.h"

namespace ccm
{
	Texture::Texture(std::string_view textureSource) : m_texture(nullptr, SDL_DestroyTexture)
	{
		auto[pTex, width, height, pitch] = TextureGenerator::loadTextureFromFile(textureSource);
		m_texture.reset(pTex);
		m_width = width;
		m_height = height;
		m_pitch = pitch;
	}

	SDL_Texture* Texture::draw() const
	{
		return m_texture.get();
	}

	int Texture::width() const
	{
		return m_width;
	}

	int Texture::height() const
	{
		return m_height;
	}

}