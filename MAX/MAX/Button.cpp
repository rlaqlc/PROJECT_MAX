#include "Button.h"

Button::Button()
{
	BtnSpriteClips = new SDL_Rect[BUTTON_SPRITE_TOTAL];
	btnSprite = BUTTON_SPRITE_MOUSE_OUT;
	texture = NULL;
	width = 0;
	height = 0;
	renderer = NULL;
	
}

void Button::handleEvent(SDL_Event * e)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < mPosition.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			btnSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				btnSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				btnSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				btnSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}

void Button::draw()
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { mPosition.x, mPosition.y, width, height };

	//Set clip rendering dimensions
	if (BtnSpriteClips != NULL)
	{
		renderQuad.w = BtnSpriteClips[btnSprite].w;
		renderQuad.h = BtnSpriteClips[btnSprite].h;
	}


	SDL_RenderCopyEx(renderer, texture, &BtnSpriteClips[btnSprite], &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}


Button::~Button()
{
}

bool Button::loadMedia(std::string filepath)
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
void Button::free()
{
	SDL_DestroyTexture(texture);
	width = 0;
	height = 0;
	texture = NULL;
}
