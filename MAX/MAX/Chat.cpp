#include "Chat.h"



Chat::Chat()
{
	SDL_ShowCursor(0);
}

void Chat::start()
{
	// to start, create a new renderer 
	createNewRenderer();

	background->setRenderer(renderer);
	background->loadMedia("resources/background.png");
	

	bool quit = false;

	SDL_Event e;
	std::cout << "Chat Activity Started!\n";

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
		SDL_SetRenderDrawColor(background->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(background->getRenderer());
		background->draw();
		SDL_RenderPresent(background->getRenderer());
	}
}


Chat::~Chat()
{
}
