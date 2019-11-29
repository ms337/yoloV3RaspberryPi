
// #include "DatabaseReader.h"
// using namespace std;

// DatabaseReader::DatabaseReader()
// {
//    sqlite3 *db;
//    struct myObj structArr[10];
//    structArrCounter = 0;
//    int rc = sqlite3_open("test.db", &db);
//    if (rc)
//    {

//       cerr << "Can't open database: " << sqlite3_errmsg(this->db) << endl;
//       exit(-1);
//    }
// }

// DatabaseReader::~DatabaseReader()
// {
//    sqlite3_close(this->db);
// }

// int DatabaseReader::addToList(string comp, int position)
// {
//    for (int i = 0; i < this->structArrCounter; i++)
//    {
//       if (this->structArr[i].name == comp)
//       {
//          cout << this->structArr[i].zones[position] << " ";
//          this->structArr[i].zones[position]++;
//          cout << this->structArr[i].name << " ";
//          cout << this->structArr[i].zones[position] << endl;
//       }
//       else
//       {
//          struct myObj thing;
//          thing.name = comp;
//          for (int j = 0; j < 30; j++)
//          {
//             thing.zones[j] = 0;
//          }
//          thing.zones[position] = 1;
//          this->structArr[structArrCounter] = thing;
//          this->structArrCounter++;
//       }
//    }
// }
// /**
//  * @brief Parses the entry to work on it one at a time.
//  *
//  * @param data
//  * @param argc
//  * @param argv
//  * @param azColName
//  * @return int
//  */
// static int callback(void *data, int argc, char **argv, char **azColName)
// {
//    cout << "WORKS" << endl;
//    int i;
//    int zonePos = 0;
//    for (i = 1; i < argc; i++)
//    {                      // for each column/zone
//       string s = argv[i]; // row entry for that column
//       string delimiter = " ";

//       size_t pos = 0;
//       string token;

//       while ((pos = s.find(delimiter)) != std::string::npos)
//       {                            // iterate over the string of objects
//          token = s.substr(0, pos); // 111
//          struct callbackArgs *args = (struct callbackArgs *)data;

//          for (int i = 0; i < *((args)->structArrCounter); i++)
//          {
//             if (args->structArr[i].name == token)
//             {
//                // cout << args->structArr[i].zones[zonePos] << " ";
//                args->structArr[i].zones[zonePos]++;
//                // cout << structArr[i].name << " ";
//                // cout << structArr[i].zones[zonePos] << endl;
//             }
//             else
//             {
//                struct myObj thing;
//                thing.name = token;
//                for (int j = 0; j < 30; j++)
//                {
//                   thing.zones[j] = 0;
//                }
//                thing.zones[zonePos] = 1;
//                args->structArr[*((args)->structArrCounter)] = thing;
//                args->structArrCounter++;
//             }
//          }

//          s.erase(0, pos + delimiter.length());
//       }
//       zonePos++;
//    }
// }

// vector<myObj> DatabaseReader::read()
// {

//    /*
//    string inputObjs[10] = {}; // this should get a list of all of the objects. This line and the for each loop should belong in the constructor

//    for (string i : inputObjs)
//    {
//       struct myObj thing;
//       thing.name = i;
//       for (int j = 0; j < 30; j++)
//       {
//          thing.zones[j] = 0;
//       }
//       structArr[structArrCounter] = thing;
//       structArrCounter++;
//    }*/
//    //this should be creating a new zone every time it encounters a new object

//    // sqlite3_stmt *stmt;
//    // rc = sqlite3_prepare(this->db, "SELECT * FROM trackingData", 0, &stmt, NULL);

//    // if (rc != SQLITE_OK)
//    // {
//    //    fprintf(stderr, "sql error #%d: %s\n", rc, sqlite3_errmsg(db));
//    // }
//    // else
//    // {
//    //    while ((rc = sqlite3_step(stmt)) != SQLITE_DONE)
//    //    {
//    //       switch (rc)
//    //       {
//    //       case SQLITE_BUSY:
//    //          break;
//    //       case SQLITE_ERROR:
//    //          break;
//    //       case SQLITE_ROW:
//    //       {
//    //          int n = sqlite3_column_count(stmt);
//    //          int zonePos = 0;
//    //          for (int i = 1; i < n; i++)
//    //          {
//    //             char *sD;
//    //             string s;
//    //             s = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, i)));
//    //             //  strcpy(sD, sqlite3_column_text(stmt, i)); // row entry for that column

//    //             string delimiter = " ";

//    //             size_t pos = 0;
//    //             string token;
//    //             while ((pos = s.find(delimiter)) != string::npos)
//    //             {                            // iterate over the string of objects
//    //                token = s.substr(0, pos); // 111
//    //                //struct callbackArgs *args = (struct callbackArgs *)data;

//    //                for (int i = 0; i < this->structArrCounter; i++)
//    //                {
//    //                   if (this->structArr[i].name == token)
//    //                   {
//    //                      // cout << args->structArr[i].zones[zonePos] << " ";
//    //                      this->structArr[i].zones[zonePos]++;
//    //                      // cout << structArr[i].name << " ";
//    //                      // cout << structArr[i].zones[zonePos] << endl;
//    //                   }
//    //                   else
//    //                   {
//    //                      struct myObj thing;
//    //                      thing.name = token;
//    //                      for (int j = 0; j < 30; j++)
//    //                      {
//    //                         thing.zones[j] = 0;
//    //                      }
//    //                      thing.zones[zonePos] = 1;
//    //                      this->structArr[this->structArrCounter] = thing;
//    //                      this->structArrCounter++;
//    //                   }
//    //                }

//    //                s.erase(0, pos + delimiter.length());
//    //             }
//    //             zonePos++;
//    //          }
//    //       }
//    //       }
//    //    }
//    /* Create SQL statement */

//    char *zErrMsg;
//    int rc;
//    char sql[100];
//    sprintf(sql, "SELECT * from trackingData");
//    // sql = "SELECT * from trackingData";

//    /* Execute SQL statement */

//    struct callbackArgs args;
//    args.structArrCounter = &(this->structArrCounter);
//    args.structArr = this->structArr;

//    rc = sqlite3_exec(this->db, sql, callback, 0, &zErrMsg);

//    if (rc != SQLITE_OK)
//    {
//       fprintf(stderr, "SQL error: %s\n", zErrMsg);
//       sqlite3_free(zErrMsg);
//    }
//    else
//    {
//       fprintf(stdout, "Operation done successfully\n");
//    }

//    // for structarrcounter, pushback(structarr[i])

//    vector<myObj> myVec;
//    for (int i = 0; i < this->structArrCounter; i++)
//    {
//       myVec.push_back(this->structArr[i]);
//    }
//    /*
//    ofstream myfile;
//    myfile.open("test.txt");

//    for (int i = 0; i < structArrCounter; i++)
//    {
//       cout << structArr[i].name << endl;
//       myfile << structArr[i].name << endl;

//       for (int j = 0; j < 30; j++)
//       {
//          cout << structArr[i].zones[j] << " ";
//          myfile << structArr[i].zones[j] << " ";
//       }
//       cout << endl;
//       myfile << endl;
//    }*/
//    return myVec;
// }
