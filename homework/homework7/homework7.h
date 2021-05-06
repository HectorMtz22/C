#include <stdio.h>
#include <time.h>
struct data {
    char* number;
    char* name;
    char* entry;
    char* exit;
} *employee ;
struct ad {
    int number;
    char* name;
    int pass;
} *admin ;
void welcome(struct tm*);
int isEmployee(void);
int read(FILE*);
int empleado(long int);
int administrador(void);