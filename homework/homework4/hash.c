#include <stdio.h>

// Structure for hash table
struct SaveAssign {
	char key[100];
	double value[100];
};

int count = 0;
struct SaveAssign newAssign; // newAssign is the hash table

// push the respective key with value
void pushAssign(char key, double value) {
	// Assign the key with value
	newAssign.key[count] = key;
	newAssign.value[count] = value;
	count++;
}

// read if a char match with a value
int readAssign(char f) {
	int i;

	for (i = 0; i < count; i++) {
		if (newAssign.key[i] == f) {
			printf("key: %c, value: %0.2f\n", newAssign.key[i], newAssign.value[i]);
			return newAssign.value[i];
		}
	}

	return 0;

}
