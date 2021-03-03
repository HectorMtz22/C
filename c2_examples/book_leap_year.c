#include <stdio.h> // printf

int main() {
	int year;

	for (year = 1900; year < 2100; year += 5) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			printf("%d is a leap year\n", year);
		} else {
			printf("%d is not a leap year\n", year);
		}
	}
	
}
