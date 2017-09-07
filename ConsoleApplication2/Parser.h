#pragma once

#include <string>
#include "Shape.h"

class Parser
{
public:
	Parser();
	~Parser();
	static Shape parse(std::string line);
};

