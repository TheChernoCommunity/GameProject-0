#include "Application.h"

#include <iostream>

int SDL_main(int argc, char* argv[])
{
	ccm::Application app;

	/* Game loop */
	while (!app.m_quit)
	{
		app.handleEvents();
		app.render();
	}

	return 0;
}
