#pragma once
#include <string>
#include <algorithm>

class AI
{
public:
	AI();
	void readLine(std::string line);
	std::string getResponse();
	~AI();
private:
	void think();
	std::string line;
	std::string response;

};

