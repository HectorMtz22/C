#include <stdio.h>
#include <stdlib.h>

int is_prime(int number) {
	int i, prime = 1;

	for (i = 2; i < number; i++) {
		if ((number % i) == 0) {
			prime = 0;
		} 	
	}
	return prime;
}

void to_binary(int number) {
	int i, j;
	for (i = 128; i > 0; i >>= 1) {
		if (i & number) {
			printf("1");
		} else {
			printf("0");
		}
	}
}

int main() {
	char k[3];
	int new_k, i, prime;

	printf("Write a number: ");
	scanf("%s", k);
	new_k = atoi(k);

	for (i = 1; i <= new_k; i++) {
		prime = is_prime(i);
		if (prime) {
			to_binary(i);
			printf(" number eq: %d\n", i);
		}
	}
}
