#include "Button.h"

Button::Button()
{
}

void Button::setSprite(SDL_Event * e)
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


void Button::draw(SDL_Rect *clip)
{
	//Set clip rendering dimensions if there is a sprite for the object
	if (btnSpriteClips != NULL)
	{
		mPosition.w = btnSpriteClips[btnSprite].w;
		mPosition.h = btnSpriteClips[btnSprite].h;
	}

	SDL_RenderCopyEx(renderer, texture, &btnSpriteClips[btnSprite], &mPosition, 0.0, NULL, SDL_FLIP_NONE);
}

Button::~Button()
{
}

void Button::free()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}
