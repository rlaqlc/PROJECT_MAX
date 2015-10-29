#include "MenuLogo.h"

Logo::Logo()
{
	//
}

Logo::Logo(int posX, int posY, int width, int height)
{
	this->mPosition.x = posX;
	this->mPosition.y = posY;
	this->mPosition.w = width;
	this->mPosition.h = height;
}

/**************************************************************
 * setSprite
 *
 * Sets the current sprite according to the current event type.
 * More specifically, if the current mouse position is inside
 * of a button, it will set the appropriate sprite to an object.
 * Logo doesn't have sprites, so it does nothing but throw an
 * exception.
 **************************************************************/
void Logo::setSprite(SDL_Event * e)
{
	throw std::logic_error("Function not implemented");
}

/**************************************************************
* draw
*
* Sets the rendering space (position and dimesion of an object),
* and applies the texture to a renderer.
**************************************************************/
void Logo::draw(SDL_Rect *clip)
{
	//Set rendering space and render to screen
	SDL_RenderCopy(renderer, texture, NULL, &mPosition);
}

Logo::~Logo()
{
}

void Logo::free()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}

