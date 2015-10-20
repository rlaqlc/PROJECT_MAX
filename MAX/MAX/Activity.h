#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include "UIElement.h"
#include "MenuLogo.h"
#include "Button.h"
#include "Background.h"
#include <list>

class Activity
{
public:
	Activity();
	Activity(SDL_Window *window);
	void setWindow(SDL_Window *window);
	void setRenderer(SDL_Renderer *renderer);
	virtual void start();
	~Activity();
protected:
	void createNewRenderer();
	SDL_Window* window;
	SDL_Renderer* renderer;
	UIElement *logo;
	UIElement *button;
	UIElement *background;
	std::list<UIElement*> *btnList;
};

