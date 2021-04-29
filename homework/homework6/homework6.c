#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

char linea[MAX];

char ins[MAX];

int main() {
	int c, i;
	node* n = NULL;
	node* arbolito = NULL;
	char username[MAX];
	char password[MAX];
	char temp1[MAX]; 
	char temp2[MAX];

	while((convert_to_line(username, password)) != EOF ) {
		if (strstr(ins, "add")) {
			i = 0;
			while (i != '\0') {
				temp1[i] = username[i];
				temp2[i] = password[i];
				i++;
			}

			n = insert(temp1, temp2, arbolito, 0);
			if (arbolito == NULL) {
				arbolito = n;
			}
		} else if (strstr(ins, "del")) {
			
			show(arbolito, '+');
		} else {
		printf("%s\n", arbolito->user);
			show(arbolito, '+');
		}
	}
	return 0;
}

