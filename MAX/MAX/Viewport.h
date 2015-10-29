#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>

class Viewport
{
public:
	Viewport();
	bool loadMedia(std::string filepath);
	void setBackgroundColor(SDL_Color color);
	void setDimension(int w, int h);
	void setPosition(int x, int y);
	void setRenderer(SDL_Renderer *renderer);
	SDL_Renderer *getRenderer();
	void draw();
	~Viewport();
private:
	void init();
	SDL_Texture *loadTexture(std::string filepath);
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *texture;
	SDL_Color color;
	SDL_Rect rect; // position and dimension of a viewport

};

