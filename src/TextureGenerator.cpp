#include "TextureGenerator.h"
#include "Renderer.h"

namespace ccm
{
	void TextureGenerator::create(Renderer& r)
	{
		if (!m_renderer)
		{
			m_renderer = &r;
		}
	}

	std::tuple<SDL_Texture*, int, int, int> TextureGenerator::loadTextureFromFile(std::string_view textureSource)
	{
		assert(m_renderer != nullptr && "Ensure to call TextureGenerator::Create(Renderer*) before trying to load a texture");
		// Load the image data
		int width, height, bytesPerPixel;
		void* imageData = stbi_load(textureSource.data(), &width, &height, &bytesPerPixel, STBI_rgb_alpha);

		// TODO: This will likely need to be more robust as there is probably other reasons why an image file could not be loaded
		// e.g. it is in use by another application
		assert(imageData != nullptr && "Failed to load image, ensure filepath is valid and correct");
		
		// Set the textures channel layout.
		std::uint32_t pixelFormat;
		if (bytesPerPixel == 3)
		{
			pixelFormat = SDL_PIXELFORMAT_BGR888;
		}
		else if (bytesPerPixel == 4)
		{
			pixelFormat = SDL_PIXELFORMAT_BGRA8888;
		}

		// Create Surface and generate texture
		SDL_Surface* pSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, bytesPerPixel, pixelFormat);
		pSurface->pixels = imageData;
		SDL_Texture* pTex = m_renderer->createTextureFromSurface(pSurface);

		int pitch = pSurface->pitch;

		// Free loaded image and created Surface
		stbi_image_free(imageData);
		pSurface->pixels = nullptr;
		SDL_FreeSurface(pSurface);

		return std::make_tuple(pTex, width, height, pitch);
	}

}