
#include "DatabaseReader.h"
using namespace std;

struct myObj
{
   string name;
   int zones[30];
};

DatabaseReader::DatabaseReader()
{
   sqlite3 *db;
   char *zErrMsg;
   struct myObj structArr[10];
   int structArrCounter = 0;
   int rc = sqlite3_open("test.db", &db);
   if (rc)
   {

      cerr << "Can't open database: " << sqlite3_errmsg(this->db) << endl;
      exit(-1);
   }
}

DatabaseReader::~DatabaseReader()
{
   sqlite3_close(this->db);
}

int DatabaseReader::addToList(string comp, int position)
{
   for (int i = 0; i < structArrCounter; i++)
   {
      if (structArr[i].name == comp)
      {
         cout << structArr[i].zones[position] << " ";
         structArr[i].zones[position]++;
         cout << structArr[i].name << " ";
         cout << structArr[i].zones[position] << endl;
      }
   }
}

int DatabaseReader::callback(void *data, int argc, char **argv, char **azColName)
{
   int i;
   int zonePos = 0;
   for (i = 1; i < argc; i++)
   {                      // for each column/zone
      string s = argv[i]; // row entry for that column
      string delimiter = " ";

      size_t pos = 0;
      string token;
      while ((pos = s.find(delimiter)) != std::string::npos)
      {                             // iterate over the string of objects
         token = s.substr(0, pos);  // 111
         addToList(token, zonePos); // increment the counter
         s.erase(0, pos + delimiter.length());
      }
      zonePos++;
   }
   return 0;
}

int DatabaseReader::read()
{
   string inputObjs[] = {"111", "112", "114"};

   for (string i : inputObjs)
   {
      struct myObj thing;
      thing.name = i;
      for (int j = 0; j < 30; j++)
      {
         thing.zones[j] = 0;
      }
      structArr[structArrCounter] = thing;
      structArrCounter++;
   }

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);

   if (rc)
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return (0);
   }
   else
   {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT * from trackingData";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);

   if (rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);

   ofstream myfile;
   myfile.open("test.txt");

   for (int i = 0; i < structArrCounter; i++)
   {
      cout << structArr[i].name << endl;
      myfile << structArr[i].name << endl;

      for (int j = 0; j < 30; j++)
      {
         cout << structArr[i].zones[j] << " ";
         myfile << structArr[i].zones[j] << " ";
      }
      cout << endl;
      myfile << endl;
   }
   return 0;
}
