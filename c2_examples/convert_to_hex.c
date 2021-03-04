#include <stdio.h>

int htoi();
char string[];

int main() {
	extern char string[];
	int converted;
	printf("What hex do you wanna convert? ");
	scanf("%s", string);

	converted = htoi();
	printf("The value in integer value is: %d\n", converted);
}

int htoi() {
	extern char string[];
	int new = atoi(string);
	
	return new;
}
