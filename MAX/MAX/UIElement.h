#pragma once

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <iostream>
#include <SDL_image.h>
#include <stdio.h>

enum CursorSprite
{
	CURSOR_SPRITE_OFF = 0,
	CURSOR_SPRITE_ON = 1,
	CURSOR_SPRITE_TOTAL = 2
};

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
	SDL_Rect *getCursorSpriteClips();
	SDL_Renderer *getRenderer();
	SDL_Rect getPosition();
	virtual bool loadMedia(std::string filepath);
	void free();
	virtual void draw(SDL_Rect *clip = NULL) = 0;
	virtual void setSprite(SDL_Event *e) = 0;
protected:
	SDL_Rect *btnSpriteClips;
	SDL_Rect *cursorSpriteClips;
	ButtonSprite btnSprite;
	CursorSprite cursorSprite;
	SDL_Rect mPosition;
	SDL_Texture *texture;
	SDL_Renderer* renderer;
	SDL_Surface *logo;
	TTF_Font *font;
};

