#include <stdio.h>
#include <time.h>
struct data {
    int number;
    char* name;
    long int entry;
    long int exit;
} *employee ;
struct ad {
    int number;
    char* name;
    int pass;
} *admin ;
void welcome(struct tm*);
int isEmployee(void);
int read(FILE*);