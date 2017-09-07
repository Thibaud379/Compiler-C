#include <iostream>
#include <fstream>
#include <string>
#include "Logger.h"

using namespace std;

#define NAME "TracerCompiler"



int main(int argc, char* argv[])
{
	
	bool debug = false;

	if (argc >= 3) 
	{
		if (string(argv[2]) == "debug")
		{
			debug = true;
		}
	}
	if (argc < 2)
	{
		cerr << "Usage: " << NAME << ".exe file.txt" << "\n";
		system("PAUSE");
		return 1;
	}
	Logger logger(debug);

	ifstream file(argv[1]);
	if (file)
	{
		logger.log("Reading file \"" + string(argv[1]) + "\".", Logger::INFO);
		string line;
		while (getline(file, line))
		{
			logger.log(line, Logger::DEBUG);
		}

	}
	else 
	{
		logger.log("The file \"" + string(argv[1]) + "\" couldn't be opened.", Logger::DEBUG);
		system("PAUSE");
		return 2;
	}

	system("PAUSE");
}