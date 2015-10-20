#pragma once

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>

enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class UIElement
{
public:
	UIElement();
	~UIElement();
	UIElement(int posX, int posY, int width, int height);
	void setRenderer(SDL_Renderer *renderer);
	void setPosition(int posX, int posY);
	void setDimension(int width, int height);
	SDL_Rect *getBtnSpriteClips();
	SDL_Renderer *getRenderer();
	SDL_Rect getPosition();
	virtual bool loadMedia(std::string filepath);
	void free();
	virtual void draw() = 0;
	virtual void setSprite(SDL_Event *e) = 0;
protected:
	SDL_Rect *btnSpriteClips;
	ButtonSprite btnSprite;
	SDL_Rect mPosition;
	SDL_Texture *texture;
	SDL_Renderer* renderer;
	SDL_Surface *logo;
	TTF_Font *font;
};

