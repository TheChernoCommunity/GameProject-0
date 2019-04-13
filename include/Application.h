#pragma once

#include <SDL.h>
#include <SDL_main.h>
#include <SDL_video.h>

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

		void update(float dt);
		void render();
		void handleEvents();

		bool m_quit{ false };

	private:
		SDL_Window* m_window{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
	};
}
