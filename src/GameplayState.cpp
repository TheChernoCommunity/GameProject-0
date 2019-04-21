#include "GameplayState.h"

void GameplayState::handleEvent(const SDL_Event& event)
{
	switch (event.type)
	{
		// TODO: Handle necessary events (not SDL_QUIT, that is
		// already handled) here

	default:
		break;
	}
}

void GameplayState::update()
{
	// Update tetris cell pieces, etc
	// Should also take in a deltatime in the future
}
