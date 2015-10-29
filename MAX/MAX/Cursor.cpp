#include "Cursor.h"



Cursor::Cursor()
{
}

void Cursor::draw(SDL_Rect *clip)
{
	SDL_Rect renderQuad = { mPosition.x, mPosition.y, mPosition.w, mPosition.h };
	SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

void Cursor::setSprite(SDL_Event * e)
{
}

bool Cursor::loadMedia(std::string filepath)
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
		//SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 0));

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


Cursor::~Cursor()
{
}
