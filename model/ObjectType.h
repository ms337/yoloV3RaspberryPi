#ifndef OBJECTTYPE
#define OBJECTTYPE
#include <iostream>
#include <string>
class ObjectType
{
private:
    int i;
    std::string object[80];
    std::string selectedObjects[10];

public:
    ObjectType();
    ~ObjectType();
    std::string getObject(std::string item);
    void addObject(std::string item);
};
#endif