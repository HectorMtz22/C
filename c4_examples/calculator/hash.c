#include <stdio.h>
#include <ctype.h>

// I read about structures in C
struct SaveAssign {
	char key[100];
	double value[100];
};

int count = 0;
// Assing structure
struct SaveAssign newAssign;


// Register assignments 
void pushAssign(char key, double value) {
	newAssign.key[count] = tolower(key);
	newAssign.value[count] = value;
	count++;
}

// Return the value of the key
// Transform the key to a value
int readAssign(char f) {
	int i;

	for (i = 0; i < count; i++) {
		if (newAssign.key[i] == tolower(f)) {
			printf("key: %c, value: %0.2f\n", newAssign.key[i], newAssign.value[i]);
			return newAssign.value[i];
		}
	}

	return 0;

}
