#include <sqlite3.h>
#include <iostream>
using namespace std;

bool executeSQL(sqlite3* db, const string& sql) {
    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << (errMsg ? errMsg : "Unknown error") << endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}