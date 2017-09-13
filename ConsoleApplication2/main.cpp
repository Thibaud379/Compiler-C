#include <iostream>
#include <fstream>
#include <string>
#include "Logger.h"
#include "Parser.h"

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
	Logger::_debug = debug;
	ifstream file(argv[1]);
	Parser parser;
	if (file)
	{
		Logger::log("Reading file \"" + string(argv[1]) + "\".", Logger::INFO);
		string line;
		int lineType = 0;
		while (getline(file, line))
		{

			if((lineType = parser.test(line))!=1)
			{
				switch (lineType) {
				case 0:
					break;
				case 1:
					parser.parseVar(line);
					break;
				case 2:
					parser.parse(line);
					break;
				default: 
					Logger::log("Parser::test() didn't return a proper value", Logger::WARNING);
				}
			}





			//Logger::log(line, Logger::DEBUG);
		}
	}
	else
	{
		Logger::log("The file \"" + string(argv[1]) + "\" couldn't be opened.", Logger::DEBUG);
		system("PAUSE");
		return 2;
	}

	system("PAUSE");
}
