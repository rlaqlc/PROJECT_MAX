#pragma once
#include "UIElement.h"
#include <SDL.h>
#include <string>

class Logo :
	public UIElement
{
public:
	Logo();
	Logo(int posX, int posY, int width, int height);
	void draw();
	~Logo();
};

