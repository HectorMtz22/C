#include <stdio.h> // printf

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\' 

int main() {
	int c;

	/*
	 * Another form is to make a switch case
	 * And this is sth horrible
	 * But it works like a charm
	*/

	while ((c = getchar()) != EOF) {
		if (c == TAB) { // Checks if is a TAB
			printf("\\t");
		} else if (c == BACKSPACE) { // Checks if is a BACKSPACE 
			printf("\\b");
		} else if (c == BACKSLASH) { // Checks if is a BACKSLASH 
			printf("\\\\");
		} else {
			putchar(c);	
		}
	}
	
}
