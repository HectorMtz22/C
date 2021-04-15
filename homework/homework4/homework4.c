#include <stdio.h>  // printf
#include <stdlib.h> // atof
#include <ctype.h>
#include "calc.h"

#define MAXOF 100
	
int assign = 0;

int main() {
	int type;
	double op2;
	char s[MAXOF];

	double substitute;

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/': 
				op2 = pop();
				if (op2 != 0.0) {
					push (pop() / op2);
				} else {
					printf("error: zero divisor\n");
				}
				break;

			case '=':
				// Found an assignment
				assign = 1;
				break;


			case '\n':
				if (!assign) {
					// Execute result
					printf("\t%.8g\n", pop());
				} else {
					// Assign the key  and value for hash table
					pushAssign(poplet(), pop());
					assign = 0; // Restart the variable
				}
				break;
			default: 
				if (isalpha(type)) {
					// Check if exists
					substitute = readAssign(tolower(type));
					if (substitute != 0.0) {
						push(substitute);
					} else {
						// Push letter like numbers
						pushlet(tolower(type));
					}

				} else {
					printf("error: unknown command %s\n", s);
				}
				break;
		}
	}
	return 0;
}
