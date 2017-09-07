#pragma once
#include <string>
class Shape
{
public:
	Shape();
	~Shape();
	std::string draw();
	void rotate(float angle);
	void resize(float factor);
};

