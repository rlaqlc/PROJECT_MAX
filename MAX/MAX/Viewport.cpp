#include "Viewport.h"



Viewport::Viewport()
{
	renderer = NULL;
	texture = NULL;

	rect = { 0, 0, 0, 0 };
	color = { 0, 0, 0, 0 };

	init();
}

void Viewport::init()
{
	//Initialize renderer color
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

	SDL_RenderClear(renderer);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
}

bool Viewport::loadMedia(std::string filepath)
{
	//Loading success flag
	bool success = true;

	//Load texture
	SDL_Surface *s;

	/* Creating the surface. */
	s = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);

	/* Filling the surface with color. */
	SDL_FillRect(s, NULL, SDL_MapRGB(s->format, color.r, color.g, color.b));
	texture = SDL_CreateTextureFromSurface(renderer, s);
	//texture = loadTexture(filepath);
	if (texture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	//Nothing to load
	return success;
}

void Viewport::setBackgroundColor(SDL_Color color)
{
	this->color = color;
}

void Viewport::setDimension(int h, int w)
{
	this->rect.h = h;
	this->rect.w = w;
}

void Viewport::setPosition(int x, int y)
{
	this->rect.x = x;
	this->rect.y = y;
}

void Viewport::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

SDL_Renderer * Viewport::getRenderer()
{
	return renderer;
}

void Viewport::draw()
{
	SDL_RenderSetViewport(renderer, &rect);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}
	
Viewport::~Viewport()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
}

SDL_Texture * Viewport::loadTexture(std::string filepath)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", filepath.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	this->texture = newTexture;

	return newTexture;
}
