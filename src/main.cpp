#include "Application.h"
#include "Renderer.h"
#include "Object.h"
#include "FrameTimer.h"
#include "Grid.h"
#include "Console.h"
#include "TextureGenerator.h"
#include "Texture.h"
#include <iostream>

int SDL_main(int argc, char* argv[])
{
#ifdef _DEBUG
	ccm::Console::initialize();
#endif
	ccm::Application app("Game", 1280, 720);
	ccm::Renderer renderer{ app };
	ccm::TextureGenerator::initialize(renderer);
	auto[width, height] = app.getSize();
	ccm::Texture mario("../../assets/mario.jpg");
	ccm::Object obj{ ccm::Rect{width / 2, height / 2, 128, 128}, mario };
	ccm::Grid grid(ccm::Rect{ 0, 0, width / 2, height }, 16, 18);
	ccm::Object obj2{ ccm::Rect{width / 2, height / 2 + 128, 128, 128}, ccm::Colors::Green };
	
	for (int x = 0; x < grid.getWidth(); ++x)
	{
		for (int y = 0; y < grid.getHeight(); ++y)
		{
			if (rand() % 2)
				grid.getTile(x, y).fill();
		}
	}
	ccm::FrameTimer ft{};

	obj.bindTexture(mario);
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
		//renderer.renderTexture(mario, { 0, 0, mario.getWidth(), mario.getHeight() });
		renderer.draw(obj);
		renderer.draw(obj2);
		renderer.render();
	}

	return 0;
}
