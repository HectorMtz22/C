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
	node* tree = NULL;
	while((convert_to_line()) != EOF ) {
		if (strstr(ins, "add")) {
			insert(username, password, tree, 0);
			printf("add %s\n", username);
			printf("add %s\n", password);
		} else if (strstr(ins, "del")) {
			printf("del %s\n", ins);
			show(tree, '+');
		} else {
			show(tree, '+');
		}
	}
	return 0;
}

