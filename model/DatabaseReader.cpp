
#include "DatabaseReader.h"
using namespace std;

DatabaseReader::DatabaseReader()
{
   sqlite3 *db;
   struct myObj structArr[10];
   structArrCounter = 0;
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
   for (int i = 0; i < this->structArrCounter; i++)
   {
      if (this->structArr[i].name == comp)
      {
         cout << this->structArr[i].zones[position] << " ";
         this->structArr[i].zones[position]++;
         cout << this->structArr[i].name << " ";
         cout << this->structArr[i].zones[position] << endl;
      }
      else
      {
         struct myObj thing;
         thing.name = comp;
         for (int j = 0; j < 30; j++)
         {
            thing.zones[j] = 0;
         }
         thing.zones[position] = 1;
         this->structArr[structArrCounter] = thing;
         this->structArrCounter++;
      }
   }
}
/**
 * @brief Parses the entry to work on it one at a time.
 * 
 * @param data 
 * @param argc 
 * @param argv 
 * @param azColName 
 * @return int 
 */
static int callback(void *data, int argc, char **argv, char **azColName)
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
      {                            // iterate over the string of objects
         token = s.substr(0, pos); // 111
         struct callbackArgs *args = (struct callbackArgs *)data;

         for (int i = 0; i < (args)->structArrCounter; i++)
         {
            if (args->structArr[i].name == token)
            {
               // cout << args->structArr[i].zones[zonePos] << " ";
               args->structArr[i].zones[zonePos]++;
               // cout << structArr[i].name << " ";
               // cout << structArr[i].zones[zonePos] << endl;
            }
            else
            {
               struct myObj thing;
               thing.name = token;
               for (int j = 0; j < 30; j++)
               {
                  thing.zones[j] = 0;
               }
               thing.zones[zonePos] = 1;
               args->structArr[args->structArrCounter] = thing;
               args->structArrCounter++;
            }
         }

         s.erase(0, pos + delimiter.length());
      }
      zonePos++;
   }
   return 0;
}

vector<myObj> DatabaseReader::read()
{
   //this->db

   /*
   string inputObjs[10] = {}; // this should get a list of all of the objects. This line and the for each loop should belong in the constructor

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
   }*/
   //this should be creating a new zone every time it encounters a new object

   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Create SQL statement */
   sql = "SELECT * from trackingData";

   /* Execute SQL statement */

   struct callbackArgs args;
   args.structArrCounter = this->structArrCounter;
   for (int i = 0; i < 10; i++)
   {
      args.structArr[i] = this->structArr[i];
   }

   rc = sqlite3_exec(this->db, sql, callback, &args, &zErrMsg);

   if (rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
      fprintf(stdout, "Operation done successfully\n");
   }

   // for structarrcounter, pushback(structarr[i])

   vector<myObj> myVec;
   for (int i = 0; i < this->structArrCounter; i++)
   {
      myVec.push_back(this->structArr[i]);
   }
   /*
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
   }*/
   return myVec;
}
