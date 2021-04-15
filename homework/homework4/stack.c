#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

int splet = 0;
char vallet[MAXVAL];


void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error, stack full, can't push %g\n", f);
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void pushlet(char f) {
	if (splet < MAXVAL) {
		vallet[splet++] = f;
	} else {
		printf("error, stack full, can't push %g\n", f);
	}
}


char poplet(void) {
	if (splet > 0) {
		return vallet[--splet];
	} else {
		printf("error: stack empty\n");
		return '0';
	}
}
