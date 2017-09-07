#pragma once
#include <string>

class Logger
{
	
public:
	static int DEBUG;
	static int INFO;
	static int WARNING;
	static int ERROR;
	static int FATAL;
	static std::string Levels[5];

	Logger(bool debug);
	~Logger();
	void log(std::string message, int level);
private:
	bool _debug;
};

