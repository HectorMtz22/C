#include <stdio.h>

#define WRAP 50

int main() {
	int c, count;

	while ((c = getchar()) != EOF) {
		count++;
		if (c == ' ' && count >= WRAP) {
			putchar('\n');
			count = 0;
		} else {
			putchar(c);
		}
		if (c == '\n') {
			count = 0;
		}

	}

}
