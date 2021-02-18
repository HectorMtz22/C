#include <stdio.h> //Basic i/o printf

int main() {
	int fahr, celsius; // Variables
	int lower, upper, step; // I could pass this with parameters

	lower = 0;
	upper = 300;
	step = 10;

	fahr = lower; // This is the initialization
	
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr += step; // I wrote this like in JavaScript and it works!
	}
}
