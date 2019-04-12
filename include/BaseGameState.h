#pragma once

#include <SDL.h>

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	
	virtual void handleEvent(SDL_Event& event) {}
	// TODO: Have update take in a deltatime
	virtual void update() {}
};
