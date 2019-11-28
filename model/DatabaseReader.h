#ifndef DATABASE_READER
#define DATABASE_READER

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>

struct myObj
{
    std::string name;
    int zones[30];
};

class DatabaseReader
{
private:
    sqlite3 *db;
    struct myObj structArr[10];
    int structArrCounter;

public:
    DatabaseReader();
    ~DatabaseReader();
    int addToList(std::string comp, int position);
    int callback(void *data, int argc, char **argv, char **azColName);
    int read();
};

#endif