#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

char linea[MAX];

char ins[MAX];

int main() {
	int c;
	node* n = NULL;
	node* arbolito = NULL;
	char username[MAX];
	char password[MAX];

	while((convert_to_line(username, password)) != EOF ) {
		if (strstr(ins, "add")) {
			printf("%s %s\n", username, password);
			n = insert(username, password, arbolito, 0);
			if (arbolito == NULL) {
				arbolito = n;
			}
		} else if (strstr(ins, "del")) {
			show(arbolito, '+');
		} else {
			show(arbolito, '+');
		}
	}
	return 0;
}

