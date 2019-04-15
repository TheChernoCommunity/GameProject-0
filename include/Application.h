#pragma once

#include <SDL.h>
#include <SDL_main.h>
#include <SDL_video.h>
#include <SDL_mixer.h>

#include <string_view>

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
		int m_width, m_height;
	};
}
