#include <stdio.h> // printf

/* State "In a word" statement */
#define IN 1 
#define OUT 0

int main() {
	int c, nl, nw, nc, state; // Declaration
	
	state = OUT; // Initial Values
	nl = nw = nc = 0; // Initialize Variables with 0

	while ((c = getchar()) != EOF) {
		++nc; 
		if (c == '\n') { // If c is a new line
			++nl; // Newline + 1
		}
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT; // It isn't in a word
		} else if (state == OUT) {
			state = IN;  // It is in a word
			++nw; // New Word count + 1
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
