#pragma once

#include <string_view>
#include <stb_image.h>
#include <memory>
namespace ccm
{
	class Texture
	{
	public:
		Texture(std::string_view textureSource)
		{
			int width, height, bytesPerPixel;
			void* imageData = stbi_load(textureSource.data(), &width, &height, &bytesPerPixel, STBI_rgb_alpha);
			std::uint32_t pixelFormat;
			if (bytesPerPixel == 3)
			{
				pixelFormat = SDL_PIXELFORMAT_BGR888;
			}
			else if (bytesPerPixel == 4)
			{
				pixelFormat = SDL_PIXELFORMAT_BGRA8888;
			}

			m_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, bytesPerPixel, pixelFormat);

			SDL_LockSurface(m_surface);
			
			m_surface->pixels = imageData;
			
			SDL_UnlockSurface(m_surface);
		}

		~Texture()
		{
			SDL_LockSurface(m_surface);
			stbi_image_free(m_surface->pixels);
			m_surface->pixels = nullptr;
			SDL_UnlockSurface(m_surface);
			SDL_FreeSurface(m_surface);
		}

		SDL_Surface* draw()
		{
			return m_surface;
		}
		
		int width() const
		{
			return m_surface->w;
		}

		int height() const
		{
			return m_surface->h;
		}

	private:
		SDL_Surface* m_surface;
	};
}