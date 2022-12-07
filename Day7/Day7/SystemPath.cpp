#include "SystemPath.h"
SystemPath::SystemPath(std::string completePath, long long sizeOnDisk) :
    completePath(completePath),
    sizeOnDisk(sizeOnDisk) { }

long long SystemPath::getSize()
{
    return sizeOnDisk;
}

void SystemPath::addChild(std::string childName, SystemPath* childSystemPath)
{
    children[childName] = childSystemPath;
    sizeOnDisk += childSystemPath->getSize();
}

std::string SystemPath::getCurrentPath()
{
    return completePath;
}