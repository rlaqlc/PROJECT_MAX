#include "Activity.h"

Activity::Activity()
{
	window = NULL;
	renderer = NULL;
	logo = new Logo();


	btnList = new std::list<UIElement*>();
	background = new Background();
	text = new Text();
	cursor = new Cursor();

}

Activity::Activity(SDL_Window * window)
{
	this->window = window;
}

void Activity::setWindow(SDL_Window * window)
{
	this->window = window;
}

void Activity::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

void Activity::start()
{
	// to start, create a new renderer 
	createNewRenderer();

	bool quit = false;

	SDL_Event e;
	std::cout << "Activity Started!\n";

	// main loop for the activity
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

Activity::~Activity()
{
	SDL_DestroyRenderer(renderer);
	window = NULL;
}

void Activity::createNewRenderer()
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
