#include <stdio.h>

/* count lines in input */

int main() {
	int c, nl;

	// I didn't use curly braces for the while and if and it worked

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n') // This condition check the "newlines"
			++nl;
	printf("%d\n", nl);
}
