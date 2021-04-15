#include <stdio.h>
#define BUFSIZE 100

char buflet[BUFSIZE];
int bufplet = 0;

int getlet(void) {
	return (bufplet > 0) ? buflet[--bufplet] : getchar();
}

void ungetlet(int c) {
	if (bufplet >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buflet[bufplet++] = c;
	}
}
