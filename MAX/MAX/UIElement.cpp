#include "UIElement.h"

UIElement::UIElement()
{
	logo = NULL;
	optimizedSurface = NULL;
	loadedSurface = NULL;
	window = NULL;
	position.x = 0;
	position.y = 0;
	this->posX = 0;
	this->posY = 0;
	this->width = 0;
	this->height = 0;
	mPosition.x = 0;
	mPosition.y = 0;
	BtnSpriteClips = new SDL_Rect[BUTTON_SPRITE_TOTAL];
	btnSprite = BUTTON_SPRITE_MOUSE_OUT;
	texture = NULL;
	width = 0;
	height = 0;
	renderer = NULL;
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

void UIElement::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

void UIElement::setPosition(int posX, int posY)
{
	mPosition.x = posX;
	mPosition.y = posY;
}

void UIElement::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void UIElement::handleEvent(SDL_Event * e)
{
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

void UIElement::free()
{
}

SDL_Rect * UIElement::getBtnSpriteClips()
{
	return BtnSpriteClips;
}

SDL_Renderer * UIElement::getRenderer()
{
	return renderer;
}

SDL_Point UIElement::getPosition()
{
	return mPosition;
}
