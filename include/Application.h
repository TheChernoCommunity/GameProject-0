#pragma once

#include <memory>
#include <vector>
#include <string_view>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_video.h>
#include "BaseGameState.h"

namespace ccm
{
	class Application
	{
	public:
		Application(std::string_view windowName, int width, int height);
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;
		~Application();

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
		void pushState(Args&&... args)
		{
			m_gameStates.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		}

		void popState();

		/*
		 * Gets the API-specific instance of the window
		 * @return pointer to the API-specific window instance
		 */
		SDL_Window* getWindow() { return m_window; }

		/*
		 * Gets the size of the window
		 * @return width and height of the screen
		 */
		std::pair<int, int> getSize() { return std::make_pair(m_width, m_height); };
		
	private:
		SDL_Window* m_window{ nullptr };
		std::vector<std::unique_ptr<GameState>> m_gameStates;
		int m_width, m_height;
	};
}
