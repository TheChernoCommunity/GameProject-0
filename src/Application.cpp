#include "Application.h"
#include "GameplayState.h"

#include <iostream>

namespace ccm
{
	Application::Application(std::string_view windowName, int width, int height)
		: m_width{ width }, m_height{ height }
	{
		/* Initialize SDL */
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
			m_quit = true;
			return;
		}

		/* Create window */
		m_window = SDL_CreateWindow(windowName.data(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_RESIZABLE);
		if (m_window == nullptr)
		{
			std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			m_quit = true;
			return;
		}

		/* Pushes the first state onto the stack. */
		// TODO: Change this to the start screen state or whatever later
		pushState<GameplayState>();

		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
			std::cerr << "SDL_mixer Error: " << SDL_GetError() << std::endl;
			std::cerr << "SDL_mixer Error: " << Mix_GetError() << std::endl;
			m_quit = true;
			return;
		}
	}

	Application::~Application()
	{
		/* Finalize and exit */
		Mix_CloseAudio();
		SDL_DestroyWindow(m_window);
		SDL_Quit();
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
					if (!m_gameStates.empty())
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
		if (!m_gameStates.empty())
		{
			m_gameStates.pop_back();
		}
		else
		{
			std::cerr << "Attempted to pop state off empty vector." << std::endl;
		}
	}
}
