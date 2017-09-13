#pragma once
#include <regex>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
class RegexUtils
{
public:
	RegexUtils();
	~RegexUtils();

	static std::vector<std::string> getArgs(std::string line, int key);

	



private:
	static std::vector<std::regex> keys;
	
	template<typename Out>
	static void split(const std::string & s, char delim, Out result);
	static std::vector<std::string> split(const std::string & s, char delim);
};

