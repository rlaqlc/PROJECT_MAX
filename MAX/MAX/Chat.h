#pragma once
#include "Activity.h"
class Chat :
	public Activity
{
public:
	Chat();
	void start();
	~Chat();
private:
	void playStatusMessage(int currentTime);
	void initViewports();
	Viewport * displayArea;
	Viewport * inputArea;

};

