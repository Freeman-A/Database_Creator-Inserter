#include <iostream>
#include "sqlite3\sqlite3.h"
using namespace std;

int main()
{
sqlite3* DB;
    std::string sql = "CREATE TABLE lambda("
                      "ID             INT                     NOT NULL, "
                      "NUME           TEXT                    NOT NULL, "
                      "PRENUME        TEXT                    NOT NULL, "
                      "USERNAME       TEXT                    NOT NULL, "
                      "EMAIL          TEXT                    NOT NULL, "
                      "PASSWORD       TEXT                    NOT NULL, "
                      "TYPE           INT                     NOT NULL, " /// 1 - basic, 3 - pro, 9 - admin (3^0, 3^1, 3^2)
                      "IP          INT                     NOT NULL, "
                      "PRIMARY KEY(ID) );";
          std::string ticket = "CREATE TABLE ticket("
                      "ID             INT                     NOT NULL, "
                      "ID_TICKET      INT                     NOT NULL, "
                      "USERNAME       TEXT                    NOT NULL, "
                      "EMAIL          TEXT                    NOT NULL, "
                      "TYPE           INT                     NOT NULL, " /// 1 - basic, 3 - pro, 9 - admin (3^0, 3^1, 3^2)
                      "IP          INT                     NOT NULL, "
                      "PRIMARY KEY(ID) );";
    int exit = 0;
    exit = sqlite3_open("lambda.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Eroare in crearea bazei de date" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Baza de date cu numele temp a fost creat cu succes" << std::endl;

    exit = sqlite3_open("ticket.db", &DB);
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Eroare in crearea bazei de date" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Baza de date cu numele ticket a fost creat cu succes" << std::endl;

    return 0;
}
