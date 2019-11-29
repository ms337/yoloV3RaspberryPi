#include "DatabaseWriter.h"

using namespace std;

int MAX_ZONES = 30;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	return 0;
}

DatabaseWriter *DatabaseWriter::instance = 0;

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

DatabaseWriter::~DatabaseWriter()
{
	sqlite3_close(this->db); // closes the database to preserve data
}

DatabaseWriter *DatabaseWriter::getInstance()
{
	if (instance == 0)
	{
		instance = new DatabaseWriter();
	}
	return instance;
}

void DatabaseWriter::write(vector<tuple<int, int, int>> listOfClassesFound, Zone zones[30], int objsSel[10])
{
	// for (int i = 0; i < 8; i++)
	// {
	// 	cout << "ZONE 1: " << zones[0].getZoneArray()[i] << endl;
	// }
	(this->curTime)++;

	int rc;
	char *zErrMsg;
	char *sql;
	char *curTimeString;
	char *number;

	// cout << sql << endl;

	char query[100];
	sprintf(query, "INSERT INTO trackingData (time) VALUES (%d);", this->curTime); //creates a new entry into the database with the current keyID. Has nothing in the zones at this point
	// cout << query << endl;

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

			// for (int obj = 0; obj < 10; obj++)
			// {
			// 	cout << objsSel[obj] << " ";
			// }
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

			// int i = 1; // starts at 1 because array at 0 is the keyID column, which we do not need

			// while (i <= MAX_ZONES) // up until 30 as we begin at 1, rather than less than
			// {
			// 	char parseArray[300]; // Used for the entire update statement
			// 	char dataEntry[100];  // used for the current objeccts detected for the given zone

			// 	for (vector<tuple<int, int, int>>::iterator it = listOfClassesFound.begin(); it != listOfClassesFound.end(); ++it)
			// 	{ // for each object

			// 		if (inZone(zones[i - 1], get<1>(*it), get<2>(*it)))
			// 		{ // if it is in the current zone. i-1 as the columns begin at i=1 in the database but begins at 0 in the array
			// 			char arr1[7];
			// 			sprintf(arr1, "%d ", get<0>(*it));

			// 			strcat(dataEntry, arr1);
			// 		}
			// 	}
			// 	cout << "DATA ENTRY: " << dataEntry << endl;
			// 	sprintf(parseArray, "UPDATE trackingData SET zone%d = '%s' WHERE time=%d;", i, dataEntry, this->curTime); // after looking through all the objects, we want to update the current column with all of the detected objects
			// 	// cout << parseArray << endl;
			// 	rc = sqlite3_exec(this->db, parseArray, callback, 0, &zErrMsg);

			// 	memset(parseArray, 0, 300);

			// 	memset(dataEntry, 0, 100);
			// 	i++;
			// }
		}
	}
}
int DatabaseWriter::inZone(Zone zone, int x, int y)
{

	int blX = zone.getZoneArray()[0];
	int trX = zone.getZoneArray()[4];
	int trY = zone.getZoneArray()[5];
	int blY = zone.getZoneArray()[1];

	// cout << "------" << endl;
	// cout << "blX: " << blX << endl;
	// cout << "trX:  " << trX << endl;
	// cout << "trY: " << trY << endl;
	// cout << "blY: " << blY << endl;
	// cout << "Midpoint X " << x << endl;
	// cout << "Midpoint Y" << y << endl;
	// cout << "------" << endl;

	if ((blX < x && x <= trX) && (trY < y && y <= blY))
	{
		// cout << "234567890" << endl;
		//cout << "c: " << c << endl;
		//cout << "ztl: " << z.tl.x << endl;
		//cout << "zbr: " << z.br.x << endl;
		return 1;
	}
	return 0;
}

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
		// cout << "234567890" << endl;
		//cout << "c: " << c << endl;
		//cout << "ztl: " << z.tl.x << endl;
		//cout << "zbr: " << z.br.x << endl;
		return 1;
	}
	return 0;
}

vector<struct myObj> DatabaseWriter::getVector()
{
	return this->vObj;
}

void DatabaseWriter::setNZones(int nZones)
{
	this->nZones = nZones;
}

int DatabaseWriter::getZones()
{
	return this->nZones;
}