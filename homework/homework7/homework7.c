/*
    YOU must compile like this:
    
    $ gcc homework.h aux.c homework.c
¨*/

#include <stdio.h>
#include <time.h>
#include "homework7.h"

int adminStatus = 0;

int main() {
    FILE * database;
    long int tp = time(0);
    struct tm * normalTime = localtime(&tp);
    welcome(normalTime);
    if (isEmployee()) {
        database = fopen("admin.txt", "r");
        fclose(database);
    } else {
        fopen("employees.txt", "a");
    }
    return 0;
}