#include <stdio.h> 

int main() {
	int c, i, j, k, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0'];
		} else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		} else {
			++nother;
		}
	}

	// Histogram
	printf("\nHistogram\n");
	for (j = 0; j < 10; j++) {
		printf("%d: %d times ", j, ndigit[j]);
		for (k = 1; k <= ndigit[j]; k++) {
			printf("#");
		}
		printf("\n");
	}

	printf("digits =");
	for (i = 0; i < 10; i++) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
