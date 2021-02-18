#include <stdio.h>

/*
 * Ok, this string have to be with "
 * If I put a single quote '
 * It won't work
*/
#define NW "\n"

int main() {
	int c; //Typical declaration

	/*
	 * I normally put the curly braces
	 * Because I have the habit 
	 * in JS
	*/

	while ((c = getchar()) != EOF) {
		if (c == ' ') { // Check if there are spaces
			printf(NW); // Prints a New Line
		} else {
			putchar(c); // Print the word
		}
	}
}
