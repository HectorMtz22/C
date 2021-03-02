#include <stdio.h>

#define TAB 2
#define SPACE " "

int main() {
	int c, i;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = 0; i < TAB; i++) {
				printf(SPACE);
			}
		} else {
			putchar(c);
		}
	}

}
