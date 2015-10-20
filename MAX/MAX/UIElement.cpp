#include "UIElement.h"

UIElement::UIElement()
{
	logo = NULL;
	mPosition.x = 0;
	mPosition.y = 0;
	mPosition.w = 0;
	mPosition.h = 0;
	btnSpriteClips = new SDL_Rect[BUTTON_SPRITE_TOTAL];
	btnSprite = BUTTON_SPRITE_MOUSE_OUT;
	texture = NULL;
	renderer = NULL;
	font = NULL;
}

UIElement::~UIElement()
{
	SDL_FreeSurface(logo);
	logo = NULL;
}

UIElement::UIElement(int posX, int posY, int width, int height)
{
	this->mPosition.x = posX;
	this->mPosition.y = posY;
	this->mPosition.w = width;
	this->mPosition.h = height;
}

void UIElement::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

void UIElement::setPosition(int posX, int posY)
{
	this->mPosition.x = posX;
	this->mPosition.y = posY;
}

void UIElement::setDimension(int width, int height)
{
	this->mPosition.w = width;
	this->mPosition.h = height;
}

bool UIElement::loadMedia(std::string filepath)
{
	//Get rid of preexisting texture
	free();

	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		//Initialize renderer color
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}
	}

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(filepath.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mPosition.w = loadedSurface->w;
			mPosition.h = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
		loadedSurface = NULL;
	}


	//Return success
	texture = newTexture;
	newTexture = NULL;
	return texture != NULL;
}

void UIElement::free()
{
}

SDL_Rect * UIElement::getBtnSpriteClips()
{
	return btnSpriteClips;
}

SDL_Renderer * UIElement::getRenderer()
{
	return renderer;
}

SDL_Rect UIElement::getPosition()
{
	return mPosition;
}
