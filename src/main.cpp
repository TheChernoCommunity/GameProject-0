#include "Application.h"
#include "FrameTimer.h"

#include <iostream>

int SDL_main(int argc, char* argv[])
{
	ccm::Application app;
	ccm::FrameTimer ft{};
	/* Game loop */
	while (!app.m_quit)
	{
		float dt = ft.mark();
		app.handleEvents();
		app.update(dt);
		app.render();
	}

	return 0;
}
