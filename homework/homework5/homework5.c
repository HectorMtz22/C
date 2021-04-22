#include "homework5.h"

int** matrix1; // this for look the mines
int** matrix2; // We are going to use this for print

int mines, size;

int main(int argc, char** args) {
  int i, j, k, l;
	initialize(argc, args);
	int positions[mines*2];

	for (i = 0; i < (mines); i++) {
    matrix1[(rand() % (size))][(rand() % (size))] = -1;
  }

	rellenar();




	showDiff();
	
	free_space();
	
}
