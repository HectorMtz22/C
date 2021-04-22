#include "homework5.h"

int state(int let, int num) {
	extern int **matrix1;
	extern int **matrix2;
	extern int status;
	
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
