#ifndef DATABASE_WRITER
#define DATABASE_WRITER

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
    static DatabaseWriter *instance;
    sqlite3 *db;
    int curTime; // this is super important

    int nZones;
    std::vector<struct myObj> vObj;
    DatabaseWriter();

    DatabaseWriter(const DatabaseWriter &);
    DatabaseWriter &operator=(const DatabaseWriter &);

public:
    static DatabaseWriter *
    getInstance();
    ~DatabaseWriter();
    int inZone(Zone zone, int x, int y);
    void write(std::vector<std::tuple<int, int, int>> listOfClassesFound, Zone zones[30], int objsSel[10]);

    int checkIfObjSelected(int objClassNo, int objsSel[10]);
    int objectInZone(std::tuple<int, int, int> objectFound, Zone zone);
    std::vector<struct myObj> getVector();
    void setNZones(int nZones);
    int getZones();
};

#endif