#include <ctype.h>
#include "homework5.h"

#define MAXOF 100

int** matrix1; // this for look the mines
int** matrix2; // We are going to use this for print

int status;

int mines, size;

int main(int argc, char** args) {
  int i, j, k, l;
	initialize(argc, args);
	int positions[mines*2];
	int assign, type;
	int templet, tempnum;

	char s[MAXOF];

	for (i = 0; i < (mines); i++) {
    matrix1[(rand() % (size))][(rand() % (size))] = -1;
  }

	rellenar();

	showDiff();
	printf("Type a column with a row\n");
	printf("If you type '=', it will capture the mine with a flag\n");
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atoi(s));
				break;
			case '=':
				assign = 1;
				break;


			case '\n':
				if (!assign) {
					templet = poplet();
					tempnum = pop();

					printf("%c %d \n", templet, tempnum);
					state(templet - '0', tempnum);
					detect_ceros(templet - '0', tempnum);
					if (status == -1) {
						printf("YOU LOST\n");
						show(matrix1);
					} else {
						showDiff();
					}
				} else {
					// Assign the key  and value for hash table
					assign = 0; // Restart the variable
				}
				break;
			default: 
				if (isalpha(type)) {
					pushlet(tolower(type));
				} else {
					printf("error: unknown command %s\n", s);
				}
				break;
		}
	}



	
	free_space();
	
}
