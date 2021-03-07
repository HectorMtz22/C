#include <stdio.h>

void escape(int s) {
	switch (s) {
		case '\n':
			printf("\\n");
			break;
		case '\t':
			printf("\\t");
			break;
		default:
			putchar(s);
	}
}

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		escape(c);
	}
	return 0;
}
