#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Reader
{
public:
	Reader() : count(0)
	{
	}

	std::vector<std::string> fileRead();

private:
	int count;
};
