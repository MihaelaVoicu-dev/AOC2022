#pragma once
#include <string>
#include <unordered_map>
class SystemPath
{
public:
    SystemPath(std::string completePath, long long sizeOnDisk);
    long long getSize();
    void addChild(std::string childName, SystemPath* childSystemPath);
    std::string getCurrentPath();
private:
    std::string completePath;
    long long sizeOnDisk;
    std::unordered_map<std::string, SystemPath*> children;
};