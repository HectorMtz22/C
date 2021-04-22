#include "homework5.h"
extern int **matrix1;
extern int **matrix2;
extern int status;
extern int size;

int state(int let, int num) {
	
	let -= 48;
	let--;
	num--;

	if (matrix1[num][let] == -1) {
		status = -1;
	} else {
		matrix2[num][let] = 1;
	}
	return 0;
}

int detect_ceros(int columna, int fila) {
	extern int **matrix1;
	extern int **matrix2;
	extern int size;

	columna -=48;
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
      if (matrix1[m][l] == 0 || matrix1[m][l] == 1) {
				matrix2[m][l] = 1;
				detect_ceros(m -1, l - 1);
      }
    }
  }
  return conteo;
}


void detect_blanks(int i, int j) {
	if (matrix1[i][j] == 0) {
		matrix2[i][j] = 1;
		if (i < size) {
			detect_blanks(i++, j);
		}
		if (j < size) {
			detect_blanks(0, j++);
		}
	} else {
		return;
	}
	return;
}
