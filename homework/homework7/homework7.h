#include <time.h>
struct data {
    int number;
    char* name;
    long int entry;
    long int exit;
} *people ;
void welcome(struct tm*);
int isEmployee(void);
