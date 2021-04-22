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
