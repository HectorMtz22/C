#include <stdio.h> // printf
#include <stdlib.h> // atoi

int main() {
	char c[4];
	int year, i;
	printf("Insert a year: ");
	scanf("%s", c); // Input and Save in var c
	
	year = atoi(c); // Convert string to integer
	printf("Your year is: %d\n", year); // Print year

	if ((year % 4) != 0) {
		printf("This is not a leap year\n");
	} else {
		printf("This is perfectly a leap year\n");
	}
}
