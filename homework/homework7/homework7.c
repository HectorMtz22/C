/*
    YOU must compile like this:
    
    $ gcc homework.h aux.c homework.c
¨*/

#include <stdio.h>
#include <time.h>

int main() {
    long int tp = clock();
    struct tm * normalTime = time(&tp);
    printf("%tm", normalTime );
    return 0;
}