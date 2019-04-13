#include "Application.h"
#include "Renderer.h"
#include "Object.h"
#include "Grid.h"
#include "FrameTimer.h"

#include <iostream>

int SDL_main(int argc, char* argv[])
{
	ccm::Application app("Game", 1280, 720);
	ccm::Renderer renderer{ app };
	auto[width, height] = app.getSize();
	ccm::Object obj{ ccm::Rect{width / 2, height / 2, 128, 128}, ccm::Colors::Green };

	ccm::FrameTimer ft{};
	
	// Generate and fill some of the grid elements
	ccm::Grid grid(ccm::Rect{ 0, 0, width / 2, height }, 10, 20);
	auto[columns, rows] = grid.getDimensions();
	for (int x = 0; x < columns; x++)
	{
		if (x == 5 || x == 1)
		{
			for (int y = 0; y < rows; ++y)
			{
				grid(x, y).fill();
			}
		}
	}
	
	/* Game loop */
	while (!app.m_quit)
	{
		float dt = ft.mark();
		app.handleEvents();
		renderer.clear();
		// Draw the grid
		for (const auto& o : grid.draw())
		{
			renderer.draw(o);
		}
		renderer.draw(obj);
		renderer.render();
	}

	return 0;
}
