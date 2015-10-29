#pragma once
#include "UIElement.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>

#define BUTTON_WIDTH 351
#define BUTTON_HEIGHT 117
#define TOTAL_BUTTONS 2

class Button :
	public UIElement
{
public:
	Button();
	void setSprite(SDL_Event *e);
	void draw(SDL_Rect *clip = NULL);
	~Button();
	void free();
};

