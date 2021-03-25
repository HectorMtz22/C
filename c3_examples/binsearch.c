#include <stdio.h>
#include <string.h>

int binsearch(int x, int v[], int n) {
	int low, mid, high;

	low = 0;
	high = n - 1;

	while(low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid + 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

int main() {
	int x = 5;
	int v[6] = {1, 2, 5, 6, 7, 8};
	int n = sizeof(v);

	printf("%d\n", binsearch(x, v, n));
}
