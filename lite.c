#include <stdio.h>
#include "sqlite3.h"

// Callback function to display query results
int callback(void *data, int argc, char **argv, char **azColName) {
    printf("%s:\n", (const char *)data);
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int main()
{
    printf("Hello world\n");
    sqlite3 *db;    //pointer to database
    char *errMsg=0; //collects error msg
    int rc;     //collects if function execution was succes(0) or not(!0)

    rc = sqlite3_open("lite.db", &db);  //opens or creates database
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Opened database successfully.\n");
    }


          // Create table if it doesn't exist
    const char *sql_create_table =  "CREATE TABLE IF NOT EXISTS event ("        //sql query
                                    "id INTEGER PRIMARY KEY, "
                                    "latitude REAL, "
                                    "longitude REAL, "
                                    "time TEXT);";
    rc = sqlite3_exec(db, sql_create_table, 0, 0, &errMsg); //executes sql query
    if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
    } else {
    printf("Table created successfully.\n");
    }

        //insert data

    const char *sql_select = "SELECT * FROM event;";
    const char *data = "Event Data:";
    rc = sqlite3_exec(db, sql_select, callback, (void *)data, &errMsg); //executes sql query
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // Close database connection
    sqlite3_close(db);

}