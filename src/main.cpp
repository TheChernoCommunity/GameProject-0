#include "Application.h"
#include "Renderer.h"
#include "Object.h"
#include "FrameTimer.h"
#include "Grid.h"
#include "AssetManager.h"
#include "Music.h"
#include "SFX.h"
#include "Console.h"
#include <iostream>

int SDL_main(int argc, char* argv[])
{
#ifdef _DEBUG
	ccm::Console::initialize();
#endif
	ccm::Application app("Game", 1280, 720);
	ccm::Renderer renderer{ app };

	ccm::AssetManager<ccm::Music> musicManager{};
	ccm::AssetManager<ccm::SFX> sfxManager{};
	auto bgMusic = musicManager.add("bgMusic", "assets/music/double_the_bits.ogg");
	auto rotateSFX = sfxManager.add("rotate", "assets/sfx/rotate_01.wav");
	bgMusic->setVolume(10);
	ccm::SFX::setVolume(10);
	bgMusic->play();
	rotateSFX->play();

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
