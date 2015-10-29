#include "Background.h"

Background::Background()
{
}

void Background::setSprite(SDL_Event * e)
{
	throw std::logic_error("Function not implemented");
}


void Background::draw(SDL_Rect *clip)
{
	//Set rendering space and render to screen
	SDL_RenderCopy(renderer, texture, NULL, &mPosition);
}

Background::~Background()
{
}
