#include "Application.h"
#include "Renderer.h"
#include "Object.h"
#include "FrameTimer.h"
#include "Grid.h"
#include "Console.h"
#include <iostream>

int SDL_main(int argc, char* argv[])
{
#ifdef _DEBUG
	ccm::Console::initialize();
#endif
	printf("Test\n");
	ccm::Application app("Game", 1280, 720);
	ccm::Renderer renderer{ app };
	auto[width, height] = app.getSize();
	ccm::Object obj{ ccm::Rect{width / 2, height / 2, 128, 128}, ccm::Colors::Green };
	ccm::Grid grid(ccm::Rect{ 0, 0, width / 2, height }, 16, 18);

	for (int x = 0; x < grid.getWidth(); ++x)
	{
		for (int y = 0; y < grid.getHeight(); ++y)
		{
			if (rand() % 2)
				grid.getTile(x, y).fill();
		}
	}
	ccm::FrameTimer ft{};

	/* Game loop */
	while (!app.m_quit)
	{
		float dt = ft.mark();
		app.handleEvents();
		renderer.clear();

		renderer.draw(grid.draw());
		for (const auto& o : grid.getTiles())
		{
			renderer.draw(o.draw());
		}

		renderer.draw(obj);
		renderer.render();
	}

	return 0;
}
