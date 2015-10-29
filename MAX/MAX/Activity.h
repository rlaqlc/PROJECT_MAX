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
#include "Viewport.h"
#include "Text.h"
#include "AI.h"
#include "Cursor.h"
#include "han2unicode.h"
#include <list>
#include <string>

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
	UIElement *cursor;
	Text *text;
	std::list<UIElement*> *btnList; // 2 buttons
};

