#include "Application.h"
#include "GameplayState.h"

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
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		if (m_renderer == nullptr)
		{
			std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			m_quit = true;
		}

		/* Pushes the first state onto the stack. */
		// TODO: Change this to the start screen state or whatever later
		pushState<GameplayState>();
	}

	Application::~Application()
	{
		/* Finalize and exit */
		SDL_DestroyWindow(m_window);
		SDL_Quit();
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

				default:
					if (m_gameStates.size() > 0)
					{
						m_gameStates.back()->handleEvent(event);
					}
					else
					{
						std::cerr << "No game states in vector." << std::endl;
					}
			}
		}
	}

	void Application::popState()
	{
		if (m_gameStates.size() > 0)
		{
			m_gameStates.pop_back();
		}
		else
		{
			std::cerr << "Attempted to pop state off empty vector." << std::endl;
		}
	}
}
