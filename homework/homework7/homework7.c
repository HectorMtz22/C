/*
    YOU must compile like this:
    
    $ gcc homework.h aux.c homework.c
¨*/

#include "homework7.h"

int adminStatus = 0;

int main() {
    FILE * database;
    long int tp = time(0);
    struct tm * normalTime = localtime(&tp);
    welcome(normalTime);
    adminStatus = isEmployee(); 
    if (adminStatus) {
        database = fopen("data/admin.txt", "a");
        read(database);
        fclose(database);
    } else {
        database = fopen("data/employees.txt", "a");
        read(database);
        fclose(database);
    }
    return 0;
}