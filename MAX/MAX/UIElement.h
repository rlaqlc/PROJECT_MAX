#pragma once
#include <SDL.h>
#include <string>
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
	void setWindow(SDL_Window *window);
	void setRenderer(SDL_Renderer *renderer);
	void setPosition(int posX, int posY);
	void setSize(int width, int height);
	virtual void handleEvent(SDL_Event *e) = 0;
	virtual bool loadMedia(std::string filepath);
	virtual void draw() = 0;
	virtual void free();
	SDL_Rect *getBtnSpriteClips();
	SDL_Renderer *getRenderer();
	SDL_Point getPosition();
protected:
	int posX;
	int posY;
	int width;
	int height;
	SDL_Rect *BtnSpriteClips;
	ButtonSprite btnSprite;
	SDL_Point mPosition;
	SDL_Texture *texture;
	SDL_Renderer* renderer;
	SDL_Surface *optimizedSurface;
	SDL_Surface *loadedSurface;
	SDL_Surface *logo;
	SDL_Rect position;
	SDL_Window *window;
};

