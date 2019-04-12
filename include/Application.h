#pragma once

#include <memory>
#include <vector>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_video.h>

#include "BaseGameState.h"

namespace ccm
{
	class Application
	{
	public:
		Application();
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;
		~Application();

		void render();
		void handleEvents();

		bool m_quit{ false };

		template<typename T, typename... Args>
		void replaceTopState(Args... args)
		{
			std::unique_ptr<GameState> nextState = std::make_unique<T>(args...);
			popState()
			m_gameStates.push_back(std::move(nextState));
		}

		template<typename T, typename... Args>
		void pushState(Args... args)
		{
			std::unique_ptr<GameState> nextState = std::make_unique<T>(args...);
			m_gameStates.push_back(std::move(nextState));
		}

		void popState();

	private:
		SDL_Window* m_window{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
		std::vector<std::unique_ptr<GameState>> m_gameStates;
	};
}
