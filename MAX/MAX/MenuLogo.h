#pragma once
#include "UIElement.h"
#include <SDL.h>

class Logo :
	public UIElement
{
public:
	Logo();
	int getPosX() const;
	void setPosX(int posX);
	int getPosY() const;
	void setPosY(int posY);
	int getWidth() const;
	void setWidth(int width);
	int getHeight() const;
	void setHeight(int height);
	Logo(int posX, int posY, int width, int height);
	~Logo();
private:
	bool init();
	bool loadMedia();
	int posX;
	int posY;
	int width;
	int height;
	SDL_Surface *optimizedSurface;
	SDL_Surface *loadedSurface;
};

