#include "Background.h"



Background::Background()
{
}

void Background::setSprite(SDL_Event * e)
{
}


void Background::draw()
{
	//Set rendering space and render to screen
	SDL_RenderCopy(renderer, texture, NULL, &mPosition);
}

Background::~Background()
{
}
