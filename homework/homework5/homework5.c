#include "homework5.h"

int** matrix1; // We are going to use this for print
int** matrix2; // And this for look the mines

int mines, size;

int main(int argc, char** args) {
  int i;
	initialize(argc, args);
	
	for (i = 0; i < (mines * 2); i++) {
    printf("%d\n", rand() % (size + 1));
  }

}
