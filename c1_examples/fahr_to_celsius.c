#include <stdio.h> //Basic i/o printf

int main() {
	float fahr, celsius; // Variables
	float lower, upper, step; // I could pass this with parameters

	lower = 300; // I reversed this values
	upper = 0;
	step = 10; // I changed this value

	fahr = lower; // This is the initialization
	
	/* We have a critical operation
	 * This is because we declared our variables as "integers"
	 * If I put 5/9 automatically it becomes 0 (Because Integer)
	 * Proceed with CAUTION
	*/

	// celsius = 5 * (fahr - 32) / 9;
	// This is a critical operation OJITO
	
	printf("Heading Fahrenheit to Celsius\n"); // Prints a Heading
	
	while (fahr >= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0); // New op
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr -= step; // I wrote this like in JavaScript and it works!
	}
}
