#include <stdio.h>

void show(int **matrix) {
	extern int size;
	int i, j;

	printf("    ");
	for (j = 0; j < size; j++) {
		printf(" %c ", j + 'A');
	}
	printf("\n");
	j = 0;

	for (i = 0; i < size; i++) {
		printf("%d |  ", i + 1);
		for (j = 0; j < size; j++) {
			printf("%d  ", matrix[i][j]);
		}
		printf("\n");
	}
}

void showDiff() {
	extern int **matrix1;
	extern int **matrix2;
	extern int size;
	int i, j;

	printf("    ");
	for (j = 0; j < size; j++) {
		printf(" %c ", j + 'A');
	}
	printf("\n");
	j = 0;

	for (i = 0; i < size; i++) {
		printf("%d |  ", i + 1);
		for (j = 0; j < size; j++) {
			if (matrix2[i][j] != 0) {
				printf("%d  ", matrix1[i][j]);
			} else {
				printf("#  ");

			}
		}
		printf("\n");
	}
}

int obtainNumber(int fila, int columna) {
	extern int **matrix1;
	extern int size;
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= size) {
    filaFin = size - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= size) {
    columnaFin = size - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = columnaInicio; l <= columnaFin; l++) {
      if (matrix1[m][l] == -1) {
        conteo++;
      }
    }
  }
  return conteo;
}

void rellenar() {
	extern int **matrix1;
	extern int size;
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (matrix1[i][j] != -1) {
				matrix1[i][j] = obtainNumber(i, j);
			}
		}
	}
}
