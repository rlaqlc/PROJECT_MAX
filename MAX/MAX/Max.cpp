#include "Max.h"


Max::Max()
{
	window = NULL;
	renderer = NULL;
	// initialize SDL
	init();

	logo = new Logo();
	btnList = new list<UIElement*>();
	menuActivity = new Menu(window);


}

void Max::start()
{
	menuActivity->start();
}

void Max::free()
{
	SDL_DestroyRenderer(renderer);
	
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		printf("Warning: Linear texture filtering not enabled!");
	}

	// create new renderer for the program
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// flip it
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Max::startChat()
{
	free();
	bool quit = false;

	SDL_Event e;
	cout << "Start Chat Activity Started!\n";
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

void Max::init()
{
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

		SDL_Cursor* cursor;
		cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
		SDL_SetCursor(cursor);

	}
}

bool Max::loadButton()
{	
	bool success = true;
	
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

	(*it)->loadMedia("resources/ButtonSpriteStart.png");
	++it;
	(*it)->loadMedia("resources/ButtonSpriteQuit.png");
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
