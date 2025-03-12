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
    sqlite3 *db;
    char *errMsg=0;
    int rc;

    rc = sqlite3_open("lite.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Opened database successfully.\n");
    }


    const char *sql_select = "SELECT * FROM event;";
    const char *data = "Event Data:";
    rc = sqlite3_exec(db, sql_select, callback, (void *)data, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // Close database connection
    sqlite3_close(db);

}