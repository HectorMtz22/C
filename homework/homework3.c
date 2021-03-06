#include <stdio.h> // Standard i/o 
#include <ctype.h> // isdigit

#define OUT 0
#define IN 1

int main() {
	int c;
	int parenthesis;


	while((c = getchar()) != EOF) {
		switch (c) {
			case '(':
				parenthesis++;
				break;
			case ')':
				parenthesis--;
				break;
		}
		if (!parenthesis) {
			isdigit(c) ? putchar('x') : putchar(c);
		} else {
			putchar(c);
		}
	}
}
