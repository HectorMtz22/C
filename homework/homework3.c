#include <stdio.h> // Standard i/o 
#include <ctype.h> // isdigit

#define OUT 0
#define IN 1

int main() {
	int c;
	int parenthesis, brackets, braces, single_q, double_q;
	int last_digit = OUT;


	while((c = getchar()) != EOF) {
		switch (c) {
			case '(':
				parenthesis++;
				break;
			case ')':
				parenthesis--;
				break;
			case '[':
				brackets++;
				break;
			case ']':
				brackets--;
				break;
			case '{':
				braces++;
				break;
			case '}':
				braces--;
				break;
			case '\'':
				single_q = !single_q;
				break;
			case '\"':
				double_q = !double_q;
				break;
		}
		if (!parenthesis || !brackets || !braces || !single_q || !double_q) {
			isdigit(c) ? last_digit = IN : putchar(c);
			if (!isdigit(c) && last_digit == IN) {
				putchar('x');
				last_digit = OUT;
			}
		}
		else {
			putchar(c);
		}
	}
}
