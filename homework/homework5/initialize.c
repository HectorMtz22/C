#include "homework5.h"



void initialize(int argc, char **args) {
	extern int mines;
	extern int size;
if (args[1]) {
		mines = atoi(args[1]);
	} else {
		printf("You must provide a number of mines!\n");
		return;
	}
	if (args[2]) {
		size = atoi(args[2]);
	} else {
		printf("You must provide a number of size!\n");
		return;
	}
  if (argc > 3) {
    srand(atoi(args[3]));
  } else {
    srand(time(NULL));
  }
}
