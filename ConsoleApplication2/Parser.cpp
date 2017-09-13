#include "Parser.h"
#include "Logger.h"
#include "RegexUtils.h"


Parser::Parser()
{
	varsFloat = *new std::unordered_map<std::string, float>;
	varsShape = *new std::unordered_map<std::string, Shape>;
}


Parser::~Parser()
{
}


Shape Parser::parse(std::string line)
{
	std::vector<std::string> args = RegexUtils::getArgs(line, 0);
	for (size_t i = 0; i < args.size(); i++)
	{
		std::cout << args[i] << "\n";
	}
	Shape s;
	return s;
}

void Parser::parseVar(std::string line)
{

}

int Parser::test(std::string line) const
{
	if (!line.empty()) {
		if (line.at(0) == '%')
		{
			Logger::log(line, Logger::INFO);
			return 0;
		}
		if (line.at(0) == '#')
		{
			return 1;
		}

		return 2;
	}
	return 0;
}
