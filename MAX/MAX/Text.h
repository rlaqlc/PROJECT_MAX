#pragma once

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "han2unicode.h"



class Text 
{
public:
	Text();
	void draw();
	void setRenderer(SDL_Renderer *renderer);
	bool loadMedia(std::string textureText);
	bool loadUserInput(std::string textureText);
	bool loadMedia(char * text);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void setPosition(int x, int y);
	void setDimension(int w, int h);
	int getWidth();
	~Text();
	// wchar_t* ConvertToHex(wchar_t* data);
private:
	SDL_Color color;
	SDL_Rect mPosition;
	SDL_Texture *texture;
	SDL_Renderer* renderer;
	TTF_Font *font;
};

