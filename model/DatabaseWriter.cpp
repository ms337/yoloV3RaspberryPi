/**
 * @file DatabaseWriter.cpp
 * @author Madhav (you@domain.com)
 * @brief DatabaseWriter Singleton to write to and read from DB
 * @version 0.1
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "DatabaseWriter.h"

using namespace std;

int MAX_ZONES = 30;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	return 0;
}

DatabaseWriter *DatabaseWriter::instance = 0;
/**
 * @brief Construct a new Database Writer:: Database Writer object
 * 
 */
DatabaseWriter::DatabaseWriter()
{
	nZones = 0;
	vObj;
	curTime = 0; // used as the keyid for the entire database. Auto increments each time write() is called
	char *zErrMsg;
	char *sql;

	int rc = sqlite3_open("test.db", &db); // opens  the database
	if (rc)
	{
		cerr << "Can't open database: " << sqlite3_errmsg(this->db) << endl;
		exit(-1);
	}
	else
	{
		cout << "Opened database successfully." << endl;

		sql = "CREATE TABLE IF NOT EXISTS trackingData (" // creates the table if not existing already
			  "time INT PRIMARY KEY     NOT NULL,"
			  "zone1          TEXT    ,"
			  "zone2          TEXT    ,"
			  "zone3          TEXT    ,"
			  "zone4          TEXT    ,"
			  "zone5          TEXT    ,"
			  "zone6          TEXT    ,"
			  "zone7          TEXT    ,"
			  "zone8          TEXT    ,"
			  "zone9          TEXT    ,"
			  "zone10         TEXT    ,"
			  "zone11         TEXT    ,"
			  "zone12         TEXT    ,"
			  "zone13          TEXT    ,"
			  "zone14          TEXT    ,"
			  "zone15         TEXT    ,"
			  "zone16          TEXT    ,"
			  "zone17          TEXT    ,"
			  "zone18          TEXT    ,"
			  "zone19          TEXT    ,"
			  "zone20          TEXT    ,"
			  "zone21          TEXT    ,"
			  "zone22          TEXT    ,"
			  "zone23          TEXT    ,"
			  "zone24          TEXT    ,"
			  "zone25          TEXT    ,"
			  "zone26          TEXT    ,"
			  "zone27          TEXT    ,"
			  "zone28          TEXT    ,"
			  "zone29          TEXT    ,"
			  "zone30         TEXT    );";

		/* Execute SQL statement */
		rc = sqlite3_exec(this->db, sql, callback, 0, &zErrMsg); // executes the sql statement
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		char query[100];
		sprintf(query, "DELETE FROM trackingData;"); // clears out entries from the databasefrom the last time it was used

		rc = sqlite3_exec(this->db, query, callback, 0, &zErrMsg); //executes query

		memset(query, 0, 100);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
	}
}

/**
 * @brief Destroy the Database Writer:: Database Writer object
 * 
 */
DatabaseWriter::~DatabaseWriter()
{
	sqlite3_close(this->db); // closes the database to preserve data
}
/**
 * @brief Singleton returned object
 * 
 * @return DatabaseWriter* 
 */

DatabaseWriter *DatabaseWriter::getInstance()
{
	if (instance == 0)
	{
		instance = new DatabaseWriter();
	}
	return instance;
}
/**
 * @brief  write to database 
 * 
 * @param listOfClassesFound  The list of classes of objects return from the model
 * @param zones The list of zones defined
 * @param objsSel The array of objects selected
 */
void DatabaseWriter::write(vector<tuple<int, int, int>> listOfClassesFound, Zone zones[30], int objsSel[10])
{

	(this->curTime)++;

	int rc;
	char *zErrMsg;
	char *sql;
	char *curTimeString;
	char *number;

	char query[100];
	sprintf(query, "INSERT INTO trackingData (time) VALUES (%d);", this->curTime); //creates a new entry into the database with the current keyID. Has nothing in the zones at this point

	//Inserts new row
	rc = sqlite3_exec(this->db, query, callback, 0, &zErrMsg);

	memset(query, 0, 100);

	//Check if insert works
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else // if the insert query worked
	{

		for (int colZone = 1; colZone <= MAX_ZONES; colZone++) //for each zoe
		{
			char updateQuery[300];
			string objectsFoundString = "";

			int flag = 1;
			for (auto objectFound : listOfClassesFound)
			{
				if (checkIfObjSelected(get<0>(objectFound), objsSel))
				{
					if (objectInZone(objectFound, zones[colZone - 1]))
					{
						for (auto objInV : this->vObj)
						{

							if (objInV.name.compare(to_string(get<0>(objectFound))) == 0)
							{
								flag = 0;
								objInV.zones[colZone - 1]++;
							}
						}
						if (flag)
						{
							struct myObj objInvNew;
							objInvNew.name = to_string(get<0>(objectFound));
							for (int x = 0; x < 30; x++)
							{
								objInvNew.zones[x] = 0;
							}
							objInvNew.zones[colZone - 1]++;
							this->vObj.push_back(objInvNew);
							break;
						}

						objectsFoundString = objectsFoundString + to_string(get<0>(objectFound)) + " ";
					}
				}
				sprintf(updateQuery, "UPDATE trackingData SET zone%d = '%s' WHERE time=%d", colZone, objectsFoundString.c_str(), this->curTime);
				rc = sqlite3_exec(this->db, updateQuery, callback, 0, &zErrMsg);
				memset(updateQuery, 0, 300);
			}
		}
	}
}
int DatabaseWriter::inZone(Zone zone, int x, int y)
{

	int blX = zone.getZoneArray()[0];
	int trX = zone.getZoneArray()[4];
	int trY = zone.getZoneArray()[5];
	int blY = zone.getZoneArray()[1];

	//Condition to check if midpoint in Zone
	if ((blX < x && x <= trX) && (trY < y && y <= blY))
	{

		return 1;
	}
	return 0;
}

/**
 * @brief Check if an object returh from model is selected
 * 
 * @param objClassNo label no
 * @param objsSel array of objects selected
 * @return int 
 */
int DatabaseWriter::checkIfObjSelected(int objClassNo, int objsSel[10])
{
	for (int x = 0; x < 10; x++)
	{
		if (objClassNo == objsSel[x])
		{
			return 1;
		}
	}
	return 0;
}

/**
 * @brief chec if object in zone
 * 
 * @param objectFound 
 * @param zone 
 * @return int 
 */

int DatabaseWriter::objectInZone(tuple<int, int, int> objectFound, Zone zone)
{
	int midX = get<1>(objectFound);
	int midY = get<2>(objectFound);

	int blX = zone.getZoneArray()[0];
	int trX = zone.getZoneArray()[4];
	int trY = zone.getZoneArray()[5];
	int blY = zone.getZoneArray()[1];

	if ((blX < midX && midX <= trX) && (trY < midY && midY <= blY))
	{

		return 1;
	}
	return 0;
}
/**
 * @brief get Vector of items written
 * 
 * @return vector<struct myObj> 
 */
vector<struct myObj> DatabaseWriter::getVector()
{
	return this->vObj;
}

/**
 * @brief set no of zones selected
 * 
 * @param nZones 
 */
void DatabaseWriter::setNZones(int nZones)
{

	this->nZones = nZones;
}

/**
 * @brief get no of zones selected
 * 
 * @return int 
 */
int DatabaseWriter::getZones()
{
	return this->nZones;
}