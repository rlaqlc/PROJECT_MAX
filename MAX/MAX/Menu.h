#pragma once
#include "Activity.h"
#include <stdio.h>
#include "UIElement.h"
#include "MenuLogo.h"
#include "Button.h"
#include <string>
#include "Chat.h"
#include <list>

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Menu :
	public Activity
{
public:
	Menu();
	Menu(SDL_Window *window);
	~Menu();
	void start();
private:
	bool loadButton();
	bool loadLogo();
	bool isOnButton(int &x, int &y, std::list<UIElement*>::iterator it);
};

