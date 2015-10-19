#pragma once
#include <SDL.h>
#include <stdio.h>
#include "UIElement.h"
#include "MenuLogo.h"
#include "Button.h"
#include <string>
#include <list>

#define TITLE "MAX v0.01"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Max
{
public:
	Max();
	void start();
	bool loadButton();
	bool loadLogo();
	~Max();
private:
	bool isOnButton(int &x, int &y, std::list<UIElement*>::iterator it);
	UIElement *logo;
	UIElement *button;
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
	std::list<UIElement*> *btnList;
};