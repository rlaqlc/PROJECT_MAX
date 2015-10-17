#include "MenuLogo.h"


Logo::Logo()
{
	
}

Logo::Logo(int posX, int posY, int width, int height)
{
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
}

void Logo::draw()
{
		loadedSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(loadedSurface, NULL, SDL_MapRGB(loadedSurface->format, 255, 255, 255));

		position.x = 170;
		position.y = 10;

		SDL_BlitSurface(logo, NULL, loadedSurface, &position);
		SDL_UpdateWindowSurface(window);
}


Logo::~Logo()
{
}
