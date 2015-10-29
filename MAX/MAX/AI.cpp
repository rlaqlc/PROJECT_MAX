#include "AI.h"
#include <iostream>


AI::AI()
{
}

void AI::readLine(std::string line)
{
	this->line = line;
	think();
}

std::string AI::getResponse()
{
	return response;
}


AI::~AI()
{
}

void AI::think()
{
	std::cout << line << std::endl;
	std::string copy = "[USER] ¾È³ç";
	std::cout << copy << std::endl;
	line.erase(0, 7);

	std::transform(line.begin(), line.end(), line.begin(), ::tolower);

	if (line == "hi" || line == "hello")
	{
		response = " Hello there!";
	}
	else if (line == "how are you?" || line == "how are you")
	{
		response = " I'm fine thank you and you?";
	}
	else
		response = " I don't know what you're talking about...";
}
