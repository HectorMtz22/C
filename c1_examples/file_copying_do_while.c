#include <stdio.h> // printf

/* copy input to output; 1st version */

int main () {
	int c;

	/*
	 * I try to optimize this with a 
	 * do while instead of
	 * a normal while loop
	*/

	do {
		c = getchar();
		putchar(c);
	} while (c != EOF)
}
