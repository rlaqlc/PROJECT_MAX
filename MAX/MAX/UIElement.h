#pragma once
#include <SDL.h>
#include <string>

class UIElement
{
public:
	UIElement();
	~UIElement();
	UIElement(int posX, int posY, int width, int height);
	void setWindow(SDL_Window *window);
	void setPosition(int posX, int posY);
	void setSize(int width, int height);
	bool loadMedia(std::string filepath);
	virtual void draw() = 0;
protected:
	int posX;
	int posY;
	int width;
	int height;
	SDL_Surface *optimizedSurface;
	SDL_Surface *loadedSurface;
	SDL_Surface *logo;
	SDL_Rect position;
	SDL_Window *window;
};

