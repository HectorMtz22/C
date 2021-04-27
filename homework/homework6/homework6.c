#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

char linea[MAX];

char username[MAX];
char password[MAX];
char ins[MAX];

int main() {
	int c;
	while((convert_to_line()) != EOF ) {
		if (strstr(ins, "add")) {
			printf("add %s\n", username);
			printf("add %s\n", password);
		} else if (strstr(linea, "del")) {
			printf("del %s\n", linea);
		} else {
			printf("Aqui se mostrará tu arbolito\n");
		}
	}
	return 0;
}

