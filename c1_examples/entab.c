#include <stdio.h>

#define TAB 2

int main() {
	int c, sum = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			sum += 1;
		}
		if (sum == TAB) {
			printf("\t");
			sum = 0;
		} else {
			putchar(c);
		}
	}
}
