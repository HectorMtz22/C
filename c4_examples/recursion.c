#include <stdio.h> // printf, putchar
#include <stdlib.h> // atoi

void printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10) {
		printd(n / 10);
	}
	putchar(n % 10 + '0');
}

int main (int argc, char args[]) {
	int number = 3249723;
	printd(number);
	printf("\n");
	return 0;
}
