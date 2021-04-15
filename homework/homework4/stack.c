#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

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
		printf("error: number stack empty\n");
		return 0.0;
	}
}


int splet = 0;
char vallet[MAXVAL];

void pushlet(char f) {
	int i, willStop;

	if (splet < MAXVAL) {
		for (i = 0; i < splet; i++) {
			if (vallet[i] == f) {
				printf("err: This exists");
				willStop = 1;
			} 
		}
		if (!willStop) {
			vallet[splet++] = f;
		}
	} else {
		printf("error, stack full, can't push %g\n", f);
	}
}

char poplet(void) {
	if (splet > 0) {
		return vallet[--splet];
	} else {
		printf("error: stack empty\n");
		return 0;
	}
}
