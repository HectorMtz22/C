#include <stdio.h>

void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(int v[], int left, int right) {
	int i, last;
	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

int main() {
	int number = 320349283;

	qsort(&number, 9, 9);
	printf("%d\n", number);
	return 0;
}
