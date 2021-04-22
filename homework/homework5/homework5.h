#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initialize(int, char **);
void free_space(void);
void show(int **);
int obtainNumber(int, int);
void rellenar();
void showDiff();
int state(int , int);


#define NUMBER '0'


void push(int);
void pushlet(char);
int pop(void);
char poplet(void);
int getop(char []);
int getch(void);
void ungetch(int);
