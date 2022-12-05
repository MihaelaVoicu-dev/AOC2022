#pragma once
#include <string>

class Container
{
public:
	Container(std::string elements);
	void append(std::string elements);
	std::string takeLastElementsReversed(int numberOfElements);
	std::string takeLastElements(int numberOfElements);
private:
	std::string internalElements;
};

