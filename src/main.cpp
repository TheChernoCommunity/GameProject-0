#include "Application.h"

#include <iostream>

int SDL_main(int argc, char* argv[])
{
	ccm::Application app;

	/* Game loop */
	SDL_Event event;
	while (!app.m_quit)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					app.m_quit = true;
					break;
			}
		}
		app.render();
	}

	return 0;
}
