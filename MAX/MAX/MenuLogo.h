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
	void handleEvent(SDL_Event *e);
	void draw();
	bool loadMedia(std::string filepath);
	~Logo();
private:
	void free();
};

