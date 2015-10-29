#include "Text.h"
#include <iomanip>
#include <stdlib.h>

Text::Text()
{

	color.r = 0;
	color.g = 0;
	color.b = 0;
}

void Text::draw()
{
	//Render to screen
	SDL_RenderCopyEx(renderer, texture, NULL, &mPosition, 0.0, NULL, SDL_FLIP_NONE);
}

void Text::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

bool Text::loadUserInput(std::string textureText)
{
	if (texture != NULL)
	{
		//SDL_DestroyTexture(texture);
		texture = NULL;
		mPosition.w = 0;
		mPosition.h = 0;
		SDL_RenderCopy(renderer, texture, NULL, &mPosition);
	}

	//Loading success flag
	bool success = true;

	//Open the font

	font = TTF_OpenFont("resources/ttf/NanumMyeongjo.ttf", 18);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{

		SDL_Color textColor = { 255, 255, 255 };

		//Render text surface
		//SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
		//SDL_Surface* textSurface = TTF_RenderUNICODE_Blended(font, dest1, textColor);

		SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, textureText.c_str(), textColor);
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		}
		else
		{
			//Create texture from surface pixels
			texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			if (texture == NULL)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get image dimensions
				mPosition.w = textSurface->w;
				mPosition.h = textSurface->h;
			}

			//Get rid of old surface
			SDL_FreeSurface(textSurface);
		}
	}

	return true;
}

wchar_t* ConvertToHex(wchar_t* data)
{
	return NULL;

}


bool Text::loadMedia(std::string textureText)
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		mPosition.w = 0;
		mPosition.h = 0;
		SDL_RenderCopy(renderer, texture, NULL, &mPosition);
	}

	//Loading success flag
	bool success = true;
	
	//Open the font

	font = TTF_OpenFont("resources/ttf/NanumMyeongjo.ttf", 18);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		SDL_Color textColor = { 255, 255, 255 };
		
		char *text = const_cast<char*>(textureText.c_str());
	Uint16 dest1[256]; 

		han2unicode h2u;
		h2u.hangle2unicode(text, dest1);

		//Render text surface
		//SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
		SDL_Surface* textSurface = TTF_RenderUNICODE_Blended(font, dest1, textColor);
		
		//SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, textureText.c_str(), textColor);
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		}
		else
		{
			//Create texture from surface pixels
			texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			if (texture == NULL)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get image dimensions
				mPosition.w = textSurface->w;
				mPosition.h = textSurface->h;
			}

		//	//Get rid of old surface
			SDL_FreeSurface(textSurface);
		}
	}

	return true;
}

bool Text::loadMedia(char * text)
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		mPosition.w = 0;
		mPosition.h = 0;
		SDL_RenderCopy(renderer, texture, NULL, &mPosition);
	}

	//Loading success flag
	bool success = true;

	//Open the font
	if (texture == NULL)
		font = TTF_OpenFont("resources/ttf/NanumMyeongjo.ttf", 18);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		SDL_Color textColor = { 255, 255, 255 };

		Uint16 dest1[256];

		//Render text surface
		//SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
		SDL_Surface* textSurface = TTF_RenderUNICODE_Blended(font, dest1, textColor);
		//SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, textureText.c_str(), textColor);
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		}
		else
		{
			//Create texture from surface pixels
			texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			if (texture == NULL)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get image dimensions
				mPosition.w = textSurface->w;
				mPosition.h = textSurface->h;
			}

			//Get rid of old surface
			SDL_FreeSurface(textSurface);
		}
	}
	return true;
}

void Text::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Text::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(texture, blending);
}

void Text::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Text::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void Text::setDimension(int w, int h)
{
	mPosition.h = h;
	mPosition.w = w;
}

int Text::getWidth()
{
	return mPosition.w;
}


Text::~Text()
{
}
