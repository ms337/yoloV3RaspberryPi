#include <iostream>
#include <sqlite3.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <tuple>
#include "Zone.h"

struct myObj
{
    std::string name;
    int zones[30];
};

class DatabaseWriter
{
private:
    sqlite3 *db;
    int curTime; // this is super important
    std::vector<struct myObj> vObj;

public:
    DatabaseWriter();
    ~DatabaseWriter();
    int inZone(Zone zone, int x, int y);
    void write(std::vector<std::tuple<int, int, int>> listOfClassesFound, Zone zones[30], int objsSel[10]);

    int checkIfObjSelected(int objClassNo, int objsSel[10]);
    int objectInZone(std::tuple<int, int, int> objectFound, Zone zone);
    std::vector<struct myObj> getVector();
};
