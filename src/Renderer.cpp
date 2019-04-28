
#include "Renderer.h"

#include <iostream>
#include <variant>

namespace ccm
{
	Renderer::Renderer(Application& app)
	{
		/* Create renderer */
		m_renderer = SDL_CreateRenderer(app.getWindow(), -1, SDL_RENDERER_ACCELERATED);
		if (m_renderer == nullptr)
		{
			std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			app.m_quit = true;
		}
	}
	void Renderer::clear()
	{
		setRenderColor(Colors::Black);
		SDL_RenderClear(m_renderer);
	}

	void Renderer::draw(const Object& obj)
	{
		std::visit(
			overloaded{
				[&](const Color& c) {
					setRenderColor(c);
					SDL_RenderFillRect(m_renderer, &obj.rect);
				},
				[&](const Texture* tex) {
					SDL_RenderCopy(m_renderer, &tex->draw(), NULL, &obj.rect);
				},			
			},
			obj.apperance
		);
	}

	SDL_Texture* Renderer::createTextureFromSurface(SDL_Surface* src)
	{
		return SDL_CreateTextureFromSurface(m_renderer, src);
	}

	void Renderer::renderTexture(const Texture& source, const Rect& dest)
	{
		SDL_RenderCopy(m_renderer, &source.draw(), nullptr, &dest);
	}

	void Renderer::renderSurface(SDL_Surface* source, const Rect dest)
	{
		SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer, source);
		SDL_RenderCopy(m_renderer, tex, nullptr, &dest);
		SDL_DestroyTexture(tex);
	}

	void Renderer::render()
	{
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::setRenderColor(const Color& color)
	{
		SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	}

	void Renderer::fillRect(const Rect& rect)
	{
		SDL_RenderFillRect(m_renderer, &rect);
	}
}
