#include <stdio.h>

/* Count characters in input; 1st version */
// EOF in Linux is Ctrl + D

int main () {
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc; //increment by one
	printf("%1d\n", nc);
}
