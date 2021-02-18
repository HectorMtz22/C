#include <stdio.h> // Printf

int main() {
	float celsius, fahr; // Variables used for the loop
	float initial, final, step; // Declaration of variables

	initial = 0; // Initial value
	final = 20;
	step = 2;

	// I used for instead of while loop

 for (celsius = initial; celsius <= final; celsius += step) {
	 fahr = (celsius * 1.8) + 32.0; // Magical Operation
	 printf("%2.0f\t%6.1f\n", celsius, fahr); // Prints output
 }
}
