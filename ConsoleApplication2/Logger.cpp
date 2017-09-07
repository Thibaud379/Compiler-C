#include "Logger.h"

int Logger::DEBUG = 0;
int Logger::INFO = 1;
int Logger::WARNING = 2;
int Logger::ERROR = 3;
int Logger::FATAL = 4;
std::string Logger::Levels[] = { " DEBUG "," INFO  ","WARNING"," ERROR "," FATAL " };


Logger::Logger(bool debug)
{
	_debug = debug;
	if (_debug) {
		log("DEBUG MODE ACTIVE", DEBUG);
	}
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
	if (level == FATAL) {
		system("EXIT");
	}

}
