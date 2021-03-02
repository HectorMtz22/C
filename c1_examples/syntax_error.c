#include <stdio.h>

int bracket = 0;
int parentheses = 0;
int braces = 0;

int error(char type_of_error[]);

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '(':
				parentheses++;
				break;
			case '{':
				braces++;
				break;
			case '[':
				bracket++;
				break;
			case ')':
				parentheses--;
				break;
			case '}':
				braces--;
				break;
			case ']':
				bracket--;
				break;
		}
		putchar(c);
	}

	bracket != 0 ? error("Bracket") : 0;
	parentheses != 0 ? error("Parentheses") : 0;
	braces != 0 ? error("Braces") : 0;

	return 0;
}

int error(char type_of_error[]) {
	printf("Error on %s\n", type_of_error);
	return 1;
}
