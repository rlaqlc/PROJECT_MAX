#include "MenuLogo.h"



Logo::Logo()
{
	optimizedSurface = NULL;
	loadedSurface = NULL;
	posX = 0;
	posY = 0;
	width = 0;
	height = 0;
}

int Logo::getPosX() const
{
	return 0;
}

void Logo::setPosX(int posX)
{
}

int Logo::getPosY() const
{
	return 0;
}

void Logo::setPosY(int posY)
{
}

int Logo::getWidth() const
{
	return 0;
}

void Logo::setWidth(int width)
{
}

int Logo::getHeight() const
{
	return 0;
}

void Logo::setHeight(int height)
{
}

Logo::Logo(int posX, int posY, int width, int height)
{
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
}

Logo::Logo(const Logo & rhs)
{
	posX = rhs.posX;
	posY = rhs.posY;
	width = rhs.width;
	height = rhs.height;
	optimizedSurface = rhs.optimizedSurface;
}


Logo::~Logo()
{
}
