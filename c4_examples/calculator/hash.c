#include <stdio.h>

struct SaveAssign {
	char key[100];
	double value[100];
};

int count = 0;
struct SaveAssign newAssign;

void pushAssign(char key, double value) {
	newAssign.key[count] = key;
	newAssign.value[count] = value;
	count++;
}

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
