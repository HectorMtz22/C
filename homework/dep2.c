#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 2

int is_prime(int number) {
	int i, j, keep;
	float module;
	for (i = (number - 1); i < number; i--) {
		j = i;
		keep = 0;
		while (j < number) {
			module = number % j;
			if (module == 0) {
				keep = 0;
				break;
			} else {
				keep = 1;
			}
			j--;
		}
		if (keep == 1) {
			printf("This is a prime number: %d\n", i);
		}
	}
	return 1;
}

int main() {
	int i, b, new_k;
	char k[3];

	printf("Write a number: ");
	scanf("%s", k);


	new_k = atoi(k);

	is_prime(new_k);

	for (i = 0; i < new_k; i++) {
		b = new_k | i;
		// printf("%d\n", b);
	}
}

