#include "Application.h"

#include <iostream>

namespace ccm
{
	Application::Application()
	{
		/* Initialize SDL */
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
			m_quit = true;
			return;
		}

		/* Create window */
		m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
		if (m_window == nullptr)
		{
			std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			m_quit = true;
			return;
		}

		/* Create renderer */
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_renderer == nullptr)
		{
			std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			m_quit = true;
		}
	}

	Application::~Application()
	{
		/* Finalize and exit */
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void Application::update(float dt)
	{

	}

	void Application::render()
	{
		SDL_RenderClear(m_renderer);
		SDL_RenderPresent(m_renderer);
	}

	void Application::handleEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					m_quit = true;
					break;
			}
		}
	}
}
