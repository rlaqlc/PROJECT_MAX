#pragma once
#include "UIElement.h"
class Background :
	public UIElement
{
public:
	Background();
	void setSprite(SDL_Event *e);
	void draw(SDL_Rect *clip = NULL);
	~Background();
};

