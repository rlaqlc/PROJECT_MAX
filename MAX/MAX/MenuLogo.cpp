#include "MenuLogo.h"


Logo::Logo()
{
	this->posX = 0;
	this->posY = 0;
	this->width = 0;
	this->height = 0;
}

Logo::Logo(int posX, int posY, int width, int height)
{
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
}

void Logo::handleEvent(SDL_Event * e)
{
	;
}

void Logo::draw()
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { mPosition.x, mPosition.y, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

bool Logo::loadMedia(std::string filepath)
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
	loadedSurface = IMG_Load(filepath.c_str());

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
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);

	}


	//Return success
	texture = newTexture;
	newTexture = NULL;
	return texture != NULL;
}


Logo::~Logo()
{
}

void Logo::free()
{
	SDL_DestroyTexture(texture);
	width = 0;
	height = 0;
	texture = NULL;
}

