#pragma once
#include <SDL.h>
#include <stdio.h>
#include "UIElement.h"
#include "MenuLogo.h"
#include <string>

class Max
{
public:
	Max();
	void start();
	~Max();
private:
	UIElement *logo;
	SDL_Window* window;
	SDL_Surface* screenSurface;
};