#include <stdio.h> 

int histogram(int ndigit[]);

int main() {
	int c, i, nwhite, nother;
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

	histogram(ndigit); // It runs the histogram

	printf("digits =");
	for (i = 0; i < 10; i++) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}

int histogram(int ndigit[]) {
	int i, j; // For the for loops

	// Histogram
	printf("\nHistogram\n"); // Headline
	for (i = 0; i < 10; i++) {
		printf("%d: %d times ", i, ndigit[i]);
		for (j = 1; j <= ndigit[i]; j++) {
			printf("#"); // Hastags of horizontal histogram
		}
		printf("\n");
	}

	return 0;
}
