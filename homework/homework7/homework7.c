/*
    YOU must compile like this:
    
    $ gcc homework.h aux.c homework.c
¨*/

#include "homework7.h"

int adminStatus = 0;

int main() {
    int c;
    FILE * database;
    long int tp = time(0);
    struct tm * normalTime = localtime(&tp);
    welcome(normalTime);
    adminStatus = isEmployee(); 
    if (adminStatus) {
        database = fopen("data/admin.txt", "ra");
        read(database);
        fclose(database);
    } else {
        database = fopen("data/employees.txt", "ra");
        read(database);
        fclose(database);
    }

    printf("Selecciona lo que deseas hacer\n");

    if (adminStatus) {
        administrador();
    } else {
        empleado(tp);
    }

    return 0;
}