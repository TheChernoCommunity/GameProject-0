#pragma once

#include <SDL.h>

class GameState
{
public:
	GameState() = default;
	virtual ~GameState() = default;
	
	virtual void handleEvent(const SDL_Event& event) {}
	// TODO: Have update take in a deltatime
	virtual void update() {}
};
