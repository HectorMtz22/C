#include <stdlib.h>

void free_space() {
	extern int size;
	extern int** matrix1;
	extern int** matrix2;
	int i;
for (i = 0; i < size; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
  }
  free(matrix1);
  free(matrix2);
}
