#pragma once
#include "UIElement.h"
class Cursor :
	public UIElement
{
public:
	Cursor();
	virtual void draw(SDL_Rect *clip = NULL);
	virtual void setSprite(SDL_Event *e);
	bool loadMedia(std::string filepath);
	~Cursor();
};

