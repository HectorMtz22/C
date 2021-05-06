/*
    YOU must compile like this:
    
    $ gcc homework.h aux.c homework.c
¨*/

#include <stdio.h>
#include <time.h>
#include "homework7.h"


int main() {
    long int tp = time(0);
    struct tm * normalTime = localtime(&tp);
    welcome(normalTime);
    printf("%d", isEmployee());
    return 0;
}