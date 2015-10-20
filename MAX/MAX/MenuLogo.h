#pragma once
#include "UIElement.h"
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <stdio.h>
#define LOGO_WIDTH 298
#define LOGO_HEIGHT 61



class Logo :
	public UIElement
{
public:
	Logo();
	Logo(int posX, int posY, int width, int height);
	void setSprite(SDL_Event *e);
	void draw();
	~Logo();
private:
	void free();
};

