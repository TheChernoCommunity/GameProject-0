#include "Texture.h"

namespace ccm
{
	Texture::Texture(std::string_view textureSource)
	{
		auto[pTex, width, height, pitch] = TextureGenerator::getInstance().loadTextureFromFile(textureSource);
		m_texture.reset(pTex);
		m_width = width;
		m_height = height;
		m_pitch = pitch;
	}

	SDL_Texture& Texture::draw() const
	{
		return *m_texture;
	}

	int Texture::getWidth() const
	{
		return m_width;
	}

	int Texture::getHeight() const
	{
		return m_height;
	}

	std::pair<int, int> Texture::getDimensions() const
	{
		return std::make_pair(m_width, m_height);
	}

	void Texture::TextureDeleter::operator()(SDL_Texture* texture)
	{
		if (texture)
			SDL_DestroyTexture(texture);
	}
}