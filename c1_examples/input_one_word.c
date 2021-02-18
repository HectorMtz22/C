#include <stdio.h>

/*
 * Ok, this string have to be with "
 * If I put a single quote '
 * It won't work
*/
#define NW "\n"

int main() {
	int c; //Typical declaration

	while ((c = getchar()) != EOF) {
		if (c == ' ') { // Check if there are spaces
			printf(NW); // Prints a New Line
		} else {
			putchar(c); // Print the word
		}
	}
}
