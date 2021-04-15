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
				assign = 1;
				break;


			case '\n':
				if (!assign) {
					printf("\t%.8g\n", pop());
				} else {
					pushAssign(poplet(), pop());
					assign = 0;
				}
				break;
			default: 
				if (isalpha(type)) {
					substitute = readAssign(type);
					if (substitute != 0.0) {
						push(substitute);
					} else {
						pushlet(type);
					}

				} else {
					printf("error: unknown command %s\n", s);
				}
				break;
		}
	}
	return 0;
}
