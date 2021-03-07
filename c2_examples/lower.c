#include <stdio.h>
#include <ctype.h>

int main() {
	int c;
	int is_lower;

	while((c = getchar()) != EOF) {
		is_lower = islower(c);
		is_lower ? putchar(c) : putchar(tolower(c));
	}
	return 0;
}
