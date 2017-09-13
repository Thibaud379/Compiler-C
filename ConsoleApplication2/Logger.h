#pragma once
#include <string>

class Logger
{
	
public:
	static const int DEBUG = 0;
	static const int INFO = 1;
	static const int WARNING = 2;
	static const int ERROR = 3;
	static const int FATAL = 3;
	static bool _debug;

	Logger();
	~Logger();
	static void log(std::string message, int level);
private:
	
	static std::string Levels[5];
};

