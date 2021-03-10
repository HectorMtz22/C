#include <stdio.h> // Standard i/o 
#include <ctype.h> // isdigit

#define OUT 0
#define IN 1

int main() {
	int c;
	int last_digit = OUT;
	int single_q, double_q;
	single_q = double_q = 0;
	int ignore = 0;
	int number = 0;

	char c_in[3] = "({[";
	char c_out[3] = ")}]";



	while((c = getchar()) != EOF) {
		ignore = 0;
		for (int i = 0; i < 3; i++) {
			if (c == c_in[i]) {
				number++;
			}
			if (c == c_out[i]) {
				number--;
			}
		}
		switch (c) {
			case '\'':
				single_q = !single_q;
				break;
			case '\"':
				double_q = !double_q;
				break;
			case '.': case ',': case ';':
				ignore = 1;
				break;
		}
		if (ignore) {
			continue;
		}
		if ((!number) && (!single_q) && (!double_q)) {
			if (!isdigit(c) && last_digit == IN) {
				putchar('x');
				last_digit = OUT;
			}
			isdigit(c) ? last_digit = IN : putchar(c);
		}
		else {
			putchar(c);
		}
	}

	printf("%d Items Left\n", number);
	printf("%d Single Quotes Left\n", single_q);
	printf("%d Double Quotes Left\n", double_q);
	printf("Have a Nice Day :) I'm hectormtz\n");
}
