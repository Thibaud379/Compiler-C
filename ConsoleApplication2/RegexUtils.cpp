#include "RegexUtils.h"

std::regex keyAll("(^\\w+)\\((.+)\\)$");
std::vector<std::regex> RegexUtils::keys = { keyAll };

RegexUtils::RegexUtils()
{
}


RegexUtils::~RegexUtils()
{
}

std::vector<std::string> RegexUtils::getArgs(std::string line, int key)
{
	std::vector<std::string> args;
	std::smatch match;
	if (std::regex_search(line, match, keys[key]))
	{
		//std::cout << args.size() << 1 << "\n";
		args.push_back(match[1].str());
		//std::cout << args.size() << 2 << "\n";
		std::vector<std::string> pars = split(match[2].str(), ',');
		
		args.reserve(args.size() + pars.size());
		args.insert(args.end(), pars.begin(), pars.end());
	}

	return args;
}

template<typename Out>
void RegexUtils::split(const std::string &s, char delim, Out result) 
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) 
	{
		*(result++) = trim(item);
	}
}

std::vector<std::string> RegexUtils::split(const std::string &s, char delim) 
{
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

const char* ws = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t = ws)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t = ws)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (left & right)
inline std::string& trim(std::string& s, const char* t = ws)
{
    return ltrim(rtrim(s, t), t);
}