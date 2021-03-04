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

int main() {
	char k[3];
	int new_k, i, prime;

	printf("Write a number: ");
	scanf("%s", k);
	new_k = atoi(k);

	for (i = 1; i <= new_k; i++) {
		prime = is_prime(i);
		if (prime) {
			printf("This is a prime number: %d\n", i);
		}
	}


}
