#include <stdio.h> // Printf

#define CELSIUS 1

#define INITIAL 0 // Initial value
#define FINAL 20
#define STEP 2

int temp(int c);
int op(int c, int t);

int main() {
	int c;

	printf("Celsius of fahrenheit, type 1 for Celsius or 0 for Fahrenheit\n");
	scanf("%d", &c); // Assing to c the correct value
	temp(c); // Call the temp function

	return 0;
}

int temp(int c) {
	float t, nt; // Variables used for the loop
	
	if (c == CELSIUS) {
		printf("Celsius to Fahrenheit\n"); // Heading
	} else {
		printf("Fahrenheit to Celsius\n");
	}

	// I used for instead of while loop

 for (t = INITIAL; t <= FINAL; t += STEP) {
	 nt = op(c, t); // Call the function to determine operation
	 printf("%2.0f\t%6.1f\n", t, nt); // Prints output
 }
}

int op(int c, int t) {
	int nt;

	if (c == CELSIUS) {
		nt = (t * 1.8) + 32.0; // To Celsius 
	} else {
		nt = (t - 32.0) / 1.8;  // To Fahrenheit
	}

	return nt; // Return new value
}
