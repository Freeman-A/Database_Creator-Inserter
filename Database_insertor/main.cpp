#include <iostream>
#include "sqlite3.h"
#include <ostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv)
{
    string* baza_de_date = new string(argv[1]);
    sqlite3* DB;
    string temp1(argv[2]);
    int exit = sqlite3_open(baza_de_date->c_str(), &DB);
    string s("INSERT INTO ");
    s+=temp1;
    string temp2(" VALUES(");
    s+=temp2;
    cout<<s<<endl;
    for (int i=3; i<argc; i++){
        if(i == 3 || i == 9){
                string temp(argv[i]);
                s += temp;
        }
        else{
            string temp(argv[i]);
        s += "'" + temp + "'";
        }
        if(i != argc - 1) s += ",";
    }

    s += ");";
    printf("%s", s.c_str());
    exit = sqlite3_exec(DB, s.c_str(), NULL, NULL, NULL);
    return 0;
}
