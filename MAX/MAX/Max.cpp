#include "Max.h"
#include <iostream>
using namespace std;

Max::Max()
{
	logo = new Logo();
	button = new Button[4];
	btnList = new list<UIElement*>();

	screenSurface = NULL;
	window = NULL;
	renderer = NULL;


	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	}
}

void Max::start()
{
	logo->setWindow(window);

	//Load media
	loadButton();
	if (!loadLogo())
	{
		printf("Failed to load media!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;
		int x;
		int y;
		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				SDL_GetMouseState(&x, &y); // current cursor position

				for (std::list<UIElement*>::iterator it = btnList->begin(); it != btnList->end(); it++) 
				{
					(*it)->handleEvent(&e);
				}
				list<UIElement*>::iterator it = btnList->begin();
				it++;
				list<UIElement*>::iterator it2 = btnList->begin();
				if (isOnButton(x, y, it)) // pass current cursor position and an iterator
				{
					cout << "you are on button2\n";
					switch (e.type)
					{
						case SDL_MOUSEBUTTONDOWN:
							quit = true;
							break;
					}
				}
				else if (isOnButton(x, y, it2))
				{
					cout << "you are on button\n";
					switch (e.type)
					{
					case SDL_MOUSEBUTTONDOWN:
						cout << "click\n";
						break;
					}
				}
				
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			SDL_SetRenderDrawColor(logo->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(logo->getRenderer());
			for (std::list<UIElement*>::iterator it = btnList->begin(); it != btnList->end(); it++) 
			{
				SDL_SetRenderDrawColor((*it)->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear((*it)->getRenderer());
			}		

			logo->draw();
			for (std::list<UIElement*>::iterator it = btnList->begin(); it != btnList->end(); it++) 
			{
				(*it)->draw();
			}

			std::list<UIElement*>::iterator it = btnList->begin();
			SDL_RenderPresent((*it)->getRenderer());
			SDL_RenderPresent(logo->getRenderer());
		}
	}
}

bool Max::loadButton()
{	
	bool success = true;
	//Load sprites


	Button * btn = new Button();
	Button * btn2 = new Button();

	btnList->push_back(btn);
	btnList->push_back(btn2);

	list<UIElement*>::iterator it = btnList->begin();

	(*it)->setRenderer(renderer);
	++it;
	(*it)->setRenderer(renderer);
	++it;

	it = btnList->begin();

	(*it)->loadMedia("resources/ButtonSprite.png");
	++it;
	(*it)->loadMedia("resources/ButtonSprite.png");
	++it;

	it = btnList->begin();

		// clip the button sprite using an array of SDL_Rect BtnSpriteClips
		// and place it in each button
			(*it)->getBtnSpriteClips()[0].x = 0;
			(*it)->getBtnSpriteClips()[0].y = 0 * 117;
			(*it)->getBtnSpriteClips()[0].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[0].h = BUTTON_HEIGHT;
			++it;
			(*it)->getBtnSpriteClips()[0].x = 0;
			(*it)->getBtnSpriteClips()[0].y = 0 * 117;
			(*it)->getBtnSpriteClips()[0].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[0].h = BUTTON_HEIGHT;
			++it;
			it = btnList->begin();
			(*it)->getBtnSpriteClips()[1].x = 0;
			(*it)->getBtnSpriteClips()[1].y = 1 * 117;
			(*it)->getBtnSpriteClips()[1].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[1].h = BUTTON_HEIGHT;
			it++;
			(*it)->getBtnSpriteClips()[1].x = 0;
			(*it)->getBtnSpriteClips()[1].y = 1 * 117;
			(*it)->getBtnSpriteClips()[1].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[1].h = BUTTON_HEIGHT;
			it++;
			it = btnList->begin();
			(*it)->getBtnSpriteClips()[2].x = 0;
			(*it)->getBtnSpriteClips()[2].y = 2 * 117;
			(*it)->getBtnSpriteClips()[2].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[2].h = BUTTON_HEIGHT;
			it++;
			(*it)->getBtnSpriteClips()[2].x = 0;
			(*it)->getBtnSpriteClips()[2].y = 2 * 117;
			(*it)->getBtnSpriteClips()[2].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[2].h = BUTTON_HEIGHT;
			it++;
			it = btnList->begin();
			(*it)->getBtnSpriteClips()[3].x = 0;
			(*it)->getBtnSpriteClips()[3].y = 3 * 117;
			(*it)->getBtnSpriteClips()[3].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[3].h = BUTTON_HEIGHT;
			it++;
			(*it)->getBtnSpriteClips()[3].x = 0;
			(*it)->getBtnSpriteClips()[3].y = 3 * 117;
			(*it)->getBtnSpriteClips()[3].w = BUTTON_WIDTH;
			(*it)->getBtnSpriteClips()[3].h = BUTTON_HEIGHT;
			it++;
			


		it = btnList->begin();
	// set each button's position
	(*it)->setPosition((SCREEN_WIDTH - BUTTON_WIDTH) / 2, 160);
	it++;
	(*it)->setPosition((SCREEN_WIDTH - BUTTON_WIDTH) / 2, 290);
	it++;
	
	for (int i = 0; i < 4; i++)
	{
		button[i].setRenderer(renderer);
		if (!button[i].loadMedia("resources/ButtonSprite.png"))
		{
			printf("Failed to load button sprite texture!\n");
			success = false;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				// clip the button sprite using an array of SDL_Rect BtnSpriteClips
				// and place it in each button
				button[j].getBtnSpriteClips()[i].x = 0;
				button[j].getBtnSpriteClips()[i].y = i * 117;
				button[j].getBtnSpriteClips()[i].w = BUTTON_WIDTH;
				button[j].getBtnSpriteClips()[i].h = BUTTON_HEIGHT;
			}

		}

	}
			// set each button's position
			button[0].setPosition(0, 0);
			button[1].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, 0);
			button[2].setPosition(0, SCREEN_HEIGHT - BUTTON_HEIGHT);
			button[3].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT);
	return success;
}

bool Max::loadLogo()
{
	bool success = true;
	logo->setRenderer(renderer);
	if (!logo->loadMedia("resources/logo.png"))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}


	logo->setPosition((SCREEN_WIDTH - LOGO_WIDTH) / 2, 45);
	
	return success;
}

Max::~Max()
{
	//Deallocate surface
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	delete logo;
	logo = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

bool Max::isOnButton(int &x, int &y, std::list<UIElement*>::iterator it)
{
	bool inside = true;

	//Mouse is left of the button
	if (x < (*it)->getPosition().x)
	{
		inside = false;
	}
	//Mouse is right of the button
	else if (x >(*it)->getPosition().x + BUTTON_WIDTH)
	{
		inside = false;
	}
	//Mouse above the button
	else if (y < (*it)->getPosition().y)
	{
		inside = false;
	}
	//Mouse below the button
	else if (y >(*it)->getPosition().y + BUTTON_HEIGHT)
	{
		inside = false;
	}
	return inside;
}
