#include "Logger.h"
#include <iostream>

std::string Logger::Levels[] = {" DEBUG "," INFO  ","WARNING"," ERROR "," FATAL "};
bool Logger::_debug = false;


Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::log(std::string message, int level)
{
	if (level != DEBUG || _debug)
	{
		if (level > WARNING)
		{
			std::cerr << "[" << Levels[level] << "] " << message << "\n";
		}
		else
		{
			std::cout << "[" << Levels[level] << "] " << message << "\n";
		}
	}
	if (level == FATAL)
	{
		system("EXIT");
	}
}


