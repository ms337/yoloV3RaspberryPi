#include <iostream>
#include <sqlite3.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <tuple>
#include "Zone.h"

class DatabaseWriter
{
private:
    sqlite3 *db;
    int curTime; // this is super important
    Zone zones[30];

public:
    DatabaseWriter(Zone zones[30]);
    ~DatabaseWriter();
    int inZone(Zone zone, int x, int y);
    void write(std::vector<std::tuple<int, int, int>> listOfClassesFound);
};
