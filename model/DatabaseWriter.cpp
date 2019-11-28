#include "DatabaseWriter.h"

using namespace std;

int MAX_ZONES = 30;

int inZone(Zone zone, int x, int y)
{
	// zone.getZoneArray();
	int topLeftX = zone.getZoneArray()[0];
	int bottomRightX = zone.getZoneArray()[4];
	int bottomRightY = zone.getZoneArray()[5];
	int topLeftY = zone.getZoneArray()[1];

	if ((topLeftX < x && x <= bottomRightX) && (topLeftY < y && y <= bottomRightY))
	{
		//cout << "c: " << c << endl;
		//cout << "ztl: " << z.tl.x << endl;
		//cout << "zbr: " << z.br.x << endl;
		return 1;
	}
	return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	return 0;
}

DatabaseWriter::DatabaseWriter(Zone zones[30])
{
	curTime = 0;
	char *zErrMsg;
	char *sql;

	for (int i = 0; i < 30; i++)
	{
		this->zones[i] = zones[i];
	}

	int rc = sqlite3_open("test.db", &db);
	if (rc)
	{

		cerr << "Can't open database: " << sqlite3_errmsg(this->db) << endl;
		exit(-1);
	}
	else
	{
		cout << "Opened database successfully." << endl;

		sql = "CREATE TABLE IF NOT EXISTS trackingData ("
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
		rc = sqlite3_exec(this->db, sql, callback, 0, &zErrMsg);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
	}
}

DatabaseWriter::~DatabaseWriter()
{
	sqlite3_close(this->db);
}

void DatabaseWriter::write(vector<tuple<int, int, int>> listOfClassesFound)
{
	this->curTime++;

	int rc;
	char *zErrMsg;
	char *sql;
	char *curTimeString;
	char *number;

	// cout << sql << endl;

	char hello[100];
	sprintf(hello, "INSERT INTO trackingData (time) VALUES (%d);", this->curTime);
	cout << hello << endl;

	rc = sqlite3_exec(this->db, hello, callback, 0, &zErrMsg);
	cout << "hi" << endl;

	memset(hello, 0, 100);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		cout << "added records" << endl;
		int i = 1;

		while (i <= MAX_ZONES)
		{
			char parseArray[300];
			char dataEntry[100];
			memset(dataEntry, 0, 100);
			for (vector<tuple<int, int, int>>::iterator it = listOfClassesFound.begin(); it != listOfClassesFound.end(); ++it)
			{ // for each object
				cout << "im here" << endl;
				if (inZone(this->zones[i], get<1>(*it), get<2>(*it)))
				{ // if it is in the zone have to create inZone and zones[]
					char arr1[7];
					sprintf(arr1, "%d", get<0>(*it));
					strcat(arr1, " ");

					/*
							int length = strlen(arr1) + strlen(arr2);
							char arr3[length];

							strcpy(arr3, arr1);
							
							strcat(arr3,arr2);
							strcat(arr3, " ");

							cout << arr3 << endl;
							*/
					strcat(dataEntry, arr1);
				}
			}

			sprintf(parseArray, "UPDATE trackingData SET zone%d = '%s' WHERE time=%d;", i, dataEntry, this->curTime);
			cout << parseArray << endl;
			rc = sqlite3_exec(this->db, parseArray, callback, 0, &zErrMsg);

			memset(parseArray, 0, 300);
			i++;
		}
	}
}
