#include <stdio.h>

struct SaveAssign {
	char key;
	double value;
};

int count = 0;
struct SaveAssign assign;

void pushAssign(char key, double value) {
	assign.key = key;
	assign.value = value;
	count++;
}

int readAssign(char f) {
	int i;

	for (i = 0; i < count; i++) {
		if (assign == f) {
			printf("%d on %c\n", assign[i].value ,assign[i].key)
		}
	}

}
