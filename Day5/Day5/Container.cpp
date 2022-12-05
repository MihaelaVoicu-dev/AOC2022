#include "Container.h"

Container::Container(std::string elements)
{
	internalElements = elements;
}

void Container::append(std::string elements)
{
	internalElements += elements;
}

std::string Container::takeLastElementsReversed(int numberOfElements)
{
	std::string lastElements = takeLastElements(numberOfElements);
	reverse(begin(lastElements), end(lastElements));
	return lastElements;
}

std::string Container::takeLastElements(int numberOfElements)
{
	long firstPosition = std::max((long)0, (long)internalElements.size() - numberOfElements);
	std::string lastElements = internalElements.substr(firstPosition, numberOfElements);
	internalElements.erase(firstPosition);
	return lastElements;
}
