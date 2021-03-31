#include <stdio.h> // For basic i/o
#include <ctype.h>

void shellsort(int v[], int n) {
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

int main(int argc[], int n) {
	int i, j, c;
	int v[100];

	j = 0;
	printf("Introduce varios números\n");
	printf("Separados entre espacios, tabs o lines\n");
	while ((c = getchar()) != EOF) {
		if (!(c == '\n') && !(c == '\t') && !(c == ' ')) {
			v[j++] = c;
		}
	}
	int el = j;
	shellsort(v, el);

	printf("Los números acomodados son: %d\n", el);
	for (i = 0; i < el; i++) {
		printf("%c\n", v[i]);
	}

}
