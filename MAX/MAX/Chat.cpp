#include "Chat.h"
//#include "h2u.h"

Chat::Chat()
{
	// mouse cursor isn't neccessary for this activity
	SDL_ShowCursor(0);
}

void Chat::playStatusMessage(int currentTime)
{
	std::string displayMessage[3];
	displayMessage[0] = "[유저]가 입장하였습니다.";
	displayMessage[1] = "[맥스]가 입장하였습니다.";

	int i = 0;
	// loop 3 times for every 2 seconds
	while (1)
	{
		if (((SDL_GetTicks() % 1000) == 0))
		{
			Text text;
			text.setRenderer(renderer);
			text.loadMedia(displayMessage[i]);
			text.setPosition(100, 30 * i + 50);
			text.draw();
			SDL_RenderPresent(renderer);
			i++;
		}

		if (i == 2)
			break;
	}
}

void Chat::initViewports()
{
	displayArea = new Viewport();
	displayArea->setRenderer(renderer);
	displayArea->setDimension(319, 541);
	displayArea->setPosition(42, 61);
	SDL_Color color;
	color.r = 63;
	color.g = 72;
	color.b = 204;
	displayArea->setBackgroundColor(color);
	displayArea->loadMedia("resources/logo.png");

	inputArea = new Viewport();
	inputArea->setRenderer(renderer);
	inputArea->setDimension(26, 510);
	inputArea->setPosition(51, 405);
	SDL_Color color2;
	color2.r = 195;
	color2.g = 195;
	color2.b = 195;
	inputArea->setBackgroundColor(color2);
	inputArea->loadMedia("resources/logo.png");

}

void Chat::start()
{
	int startTime = 0;
	int start = 0;
	// to start, create a new renderer 
	
	createNewRenderer();

	background->setRenderer(renderer);
	background->loadMedia("resources/background.png");
	background->setDimension(640, 480);
	background->draw();

	initViewports();

	displayArea->draw();

	
	text->setRenderer(renderer);
	std::string started = "채팅이 시작되었습니다.";
	text->loadMedia(started);
	text->setPosition(10, 10);
	text->setColor(255, 255, 255);
	text->draw();

	SDL_RenderPresent(renderer);

	cursor->setRenderer(renderer);
	cursor->loadMedia("resources/CursorSprite.png");

	cursor->getCursorSpriteClips()[0].x = 0;
	cursor->getCursorSpriteClips()[0].y = 0;
	cursor->getCursorSpriteClips()[0].h = 71;
	cursor->getCursorSpriteClips()[0].w = 5;

	cursor->getCursorSpriteClips()[1].x = 0;
	cursor->getCursorSpriteClips()[1].y = 71;
	cursor->getCursorSpriteClips()[1].h = 71;
	cursor->getCursorSpriteClips()[1].w = 5;

	cursor->setDimension(2, 24);
	cursor->setPosition(0, 0);

	bool quit = false;

	int currentTime = SDL_GetTicks();
	playStatusMessage(currentTime);

	SDL_Event e;
	std::cout << "채팅이 시작되었습니다.";

	Text *inputText = new Text();
	inputText->setRenderer(renderer);
	inputText->setPosition(2, 0);
	inputText->setDimension(300, 30);
	std::string inputTextstr = "";
	inputText->loadMedia(inputTextstr);
	inputText->setColor(0, 0, 0);

	int frame = 0;
	char * text = NULL;

	int i = 0;
	int j = 0;

	std::list<Text*> *textList = new std::list<Text*>();


	for (int i = 0; i < 14; i++)
	{
		Text *text = new Text();
		text->setRenderer(renderer);
		text->setPosition(10, 280 - (i * 20));
		textList->push_back(text);
	}

	Text t;
	t.setRenderer(renderer);
	t.setPosition(10, 280);

	Text t2;
	t2.setRenderer(renderer);
	t2.setPosition(10, 260);

	Text t3;
	t3.setRenderer(renderer);
	t3.setPosition(10, 240);

	Text t4;
	t4.setRenderer(renderer);
	t4.setPosition(10, 220);

	std::list<std::string> * userInput = new std::list<std::string>();
	std::list<std::string> * userInput2 = new std::list<std::string>();

	// add dummy texture
	for (int i = 0; i < 14; i++)
	{
		userInput->push_front(" ");
	}

	std::list<std::string>::iterator it = userInput->begin();

	userInput2->push_front(" ");
	userInput2->push_front(" ");
	userInput2->push_front(" ");
	userInput2->push_front(" ");


	// string for checking whether it's a user input or not
	std::string strCheck = "";

	bool renderChat = false;
	int counter = 0;
	// main loop for the activity
	while (!quit)
	{
		SDL_StartTextInput();
		bool renderText = false;

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//Special key input
			else if (e.type == SDL_KEYDOWN)
			{

				//Handle backspace
				if (e.key.keysym.sym == SDLK_BACKSPACE && inputTextstr.length() > 0)
				{
					SDL_Rect *currentClip = &cursor->getCursorSpriteClips()[0];
					cursor->draw(currentClip);
					SDL_RenderPresent(renderer);
				
					//lop off character
					inputText->loadUserInput(inputTextstr);
					
					if ((int) inputTextstr.back() >= 0 && (int) inputTextstr.back() <= 127) {
						inputTextstr.pop_back();
					}
					else
					{
						inputTextstr.pop_back();
						inputTextstr.pop_back();
						inputTextstr.pop_back();
					}
					if (inputTextstr.length() == 0)
						cursor->setPosition(2, 0);
					
					cursor->setPosition(inputText->getWidth() + 2, 0);
					renderText = true;
				}
				//Handle copy
				else if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
				{
					SDL_SetClipboardText(inputTextstr.c_str());
				}
				//Handle paste
				else if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
				{
					inputTextstr = SDL_GetClipboardText();
					renderText = true;
				}
				else if (e.key.keysym.sym == SDLK_RETURN && inputTextstr != "")
				{
					counter = 0;
					// initial frame calculation starts from here
					frame = 0;

					// renderChar after RETURN
					renderChat = true;

					std::string full = "[USER] ";

					// when you add something at the front, always pop at the end
					userInput->push_front(full += inputTextstr);
					userInput->pop_back();

					// clear the user input
					inputTextstr.clear();
					inputText->loadUserInput(inputTextstr); // display the empty texture
				
					// reset the cursor position
					cursor->setPosition(2, 0);
				
					SDL_RenderPresent(renderer);

					it = userInput->begin();

					std::list<Text*>::iterator it2 = textList->begin();
					std::cout << textList->size();
					// load text onto text object
					for (; it2 != textList->end(); ++it2)
					{
						(*it2)->loadUserInput(*it);
						(*it2)->setColor(255, 255, 255);
						it++;
					}


					/*
					t.loadUserInput(*it);
					t.setColor(255, 255, 255);

					it++;

					t2.loadUserInput(*it);
					t2.setColor(255, 255, 255);

					it++;

					t3.loadUserInput(*it);
					t3.setColor(255, 255, 255);

					it++;

					t4.loadUserInput(*it);
					t4.setColor(255, 255, 255);
					*/
					displayArea->draw();

					for (std::list<Text*>::iterator it2 = textList->begin(); it2 != textList->end(); ++it2)
					{
						(*it2)->draw();
					}

					/*
					t.draw();
					t2.draw();
					t3.draw();
					t4.draw();
					*/
					SDL_RenderPresent(renderer);

					j++;
				}
			}
			//Special text input event
			else if (e.type == SDL_TEXTINPUT)
			{
				//Not copy or pasting
				if (!((e.text.text[0] == 'c' || e.text.text[0] == 'C') && (e.text.text[0] == 'v' || e.text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL) && inputTextstr.length() < 50)
				{
					SDL_Rect *currentClip = &cursor->getCursorSpriteClips()[0];
					cursor->draw(currentClip);
					SDL_RenderPresent(renderer); 
					//Append character
					inputTextstr += e.text.text;
					renderText = true;
				}
			}
		}

		//Rerender text if needed
		if (renderText)
		{
			//Text is not empty
			if (inputTextstr != "")
			{
				inputText->loadUserInput(inputTextstr);
				inputText->setColor(0, 0, 0);
				cursor->setPosition(inputText->getWidth() + 2, 0);
			}
			//Text is empty
			else
			{
				cursor->setPosition(2, 0);
				//Render space texture
				std::string str = " ";
				inputText->loadUserInput(str);
				inputText->setColor(0, 0, 0);
			}
		}


			// every n-th iteration starting from "RETURN" event
			if (frame == 100 && renderChat)
			{
				AI max;
				std::cout << "userInput->front(): " << userInput->front() << std::endl;
				max.readLine(userInput->front());

				// when you add something at the front, always pop at the end
				userInput->push_front("[MAX]" + max.getResponse());
				userInput->pop_back();

				it = userInput->begin();

				textList->front()->loadMedia(*it);
				textList->front()->setColor(255, 255, 255);

				for (std::list<Text*>::iterator it2 = textList->begin(); it2 != textList->end(); ++it2)
				{
					it2++;
					it++;
					(*it2)->loadUserInput(*it);
					(*it2)->setColor(255, 255, 255);
				}
				/*
				it = userInput->begin();

				// load text onto text object
				t.loadUserInput(*it);
				t.setColor(255, 255, 255);

				it++;

				t2.loadUserInput(*it);
				t2.setColor(255, 255, 255);

				it++;

				t3.loadUserInput(*it);
				t3.setColor(255, 255, 255);

				it++;

				t4.loadUserInput(*it);
				t4.setColor(255, 255, 255);
				*/
				displayArea->draw();

				for (std::list<Text*>::iterator it2 = textList->begin(); it2 != textList->end(); ++it2)
				{
					(*it2)->draw();
				}
				/*
				t.draw();
				t2.draw();
				t3.draw();
				t4.draw();
				*/
				SDL_RenderPresent(renderer);
				renderChat = false;
			}

	

		// draw on chat input field
		inputArea->draw();
		inputText->draw();
		SDL_Rect *currentClip = &cursor->getCursorSpriteClips()[frame / 6];
		cursor->draw(currentClip);
		SDL_RenderPresent(renderer);
		++frame;

		if (frame / 2000  == 1)
		{
			frame = 0;
		}
		
	}
}


Chat::~Chat()
{
}
