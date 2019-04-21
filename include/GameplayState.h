#pragma once

#include "BaseGameState.h"

// This is where the main gameplay will occur
class GameplayState : public GameState
{
public:
	// Could pass in state such as settings that were
	// toggled on the start screen or stuff like that
	// Make un-default when actually needed
	GameplayState() = default;

	void handleEvent(const SDL_Event& event) override;
	void update() override;
};
