#pragma once
#include <SDL.h>
#include <stdio.h>
#include "UIElement.h"
#include "MenuLogo.h"
#include "Button.h"
#include <string>
#include <list>
#include <iostream>
#include "Activity.h"
#include "Menu.h"

using namespace std;

#define TITLE "MAX v0.01"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Max
{
public:
	Max();
	void start();
	~Max();
private:
	void free();
	void startChat();
	void init();
	bool loadButton();
	bool loadLogo();
	bool isOnButton(int &x, int &y, std::list<UIElement*>::iterator it);
	UIElement *logo;
	UIElement *button;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Activity *menuActivity;
	std::list<UIElement*> *btnList;
};