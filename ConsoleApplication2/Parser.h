#pragma once

#include <string>
#include "Shape.h"
#include <unordered_map>
#include <vector>
#include <iostream>


class Parser
{
public:
	Parser();
	~Parser();


	Shape parse(std::string line);
	void parseVar(std::string line);
	int test(std::string line) const;
	
private:
	std::unordered_map<std::string, float> varsFloat;
	std::unordered_map<std::string, Shape> varsShape;
};
