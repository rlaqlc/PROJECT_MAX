#include "UIElement.h"
#include <stdio.h>
#include <string>

UIElement::UIElement()
{
	logo = NULL;
	optimizedSurface = NULL;
	loadedSurface = NULL;
	window = NULL;
	position.x = 0;
	position.y = 0;
}


UIElement::~UIElement()
{
	//Deallocate
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;

	//Deallocate surface
	SDL_FreeSurface(optimizedSurface);
	optimizedSurface = NULL;

	SDL_FreeSurface(logo);
	logo = NULL;

	window = NULL;
}

UIElement::UIElement(int posX, int posY, int width, int height)
{
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
}


void UIElement::setWindow(SDL_Window * window)
{
	this->window = window;

}

void UIElement::setPosition(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}

void UIElement::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

bool UIElement::loadMedia(std::string filepath)
{
	//Loading success flag
	bool success = true;

	//Load splash image
	logo = SDL_LoadBMP(filepath.c_str());
	
	if (logo == NULL)
		success = false;

	return success;
}
