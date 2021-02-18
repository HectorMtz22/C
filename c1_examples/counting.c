#include <stdio.h>

int main() {
	int c, newlines, tabs, spaces;

	// Constants
	#define NEWLINE '\n'
	#define TAB '\t'
	#define SPACE ' '

	// Initialize all variables
	newlines = 0;
	tabs = 0;
	spaces = 0;

	// I used 3 ifs
	// There's for sure that switch case is even better
	while ((c = getchar()) != EOF) {
		if (c == NEWLINE) {
			newlines++;
		}
		if (c == TAB) {
			tabs++;
		}
		if (c == SPACE) {
			spaces++;
		}
	}

	printf("\nYou did %d newlines\n", newlines);
	printf("Also, You did %d tabs\n", tabs);
	printf("Finally, You did %d spaces\n", spaces);

}
