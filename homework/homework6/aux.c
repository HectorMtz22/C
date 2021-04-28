#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"
int convert_to_line() {
  extern char username[];
  extern char password[];
  extern char ins[];
  extern char linea[];
  int c, i, j, k, l;
	i = j = k = l = 0;
	int count = 0;
  for (i = 0; i < MAX  && (c = getchar()) != EOF && c != '\n'; i++) {
		if (isspace(c)) {
			count++;
			continue;
		}
		switch (count) {
			case 0:
				ins[j++] = c;
				break;
			case 1:
				username[k++] = c;
				break;
			case 2:
				password[l++] = c;
				break;
		}
  }
	ins[j] = '\0';
	username[k] = '\0';
	password[l] = '\0';
  linea[i] = '\0'; 
	return c == EOF;
}

node* insert(char* username, char* password, node* pos, int d) {
	node* temp;
	if (pos == NULL) {
		pos = (node*)malloc(sizeof(node));
		pos->username = username;
		pos->password = password;
		pos->depth = d;
	} else {
		if (pos->username == username) {
			// Aquí vendran los errores que no se puede insertar
		} else if (pos->username > username) {
			temp = insert(username, password, pos->leftChild, d + 1);
			if (pos->leftChild == NULL) {
				pos->leftChild = temp;
			}
		} else {
			temp = insert(username, password, pos->rightChild, d + 1);
			if (pos->rightChild == NULL) {
				pos->rightChild = temp;
			}
		}
	}
	return pos;
}

void show(node* pos, char prefix) {
	int i;
	char suffix = ' ';

	if (pos != NULL) {
		for (i = 0; i < pos->depth; i++) {
			printf(" ");
		}
		if (pos->leftChild == NULL && pos->rightChild == NULL) {
			suffix = '#';
		}
		printf("%c %s %s %c\n", prefix, pos->username, pos->password, suffix);
		show(pos->leftChild, '<');
		show(pos->rightChild, '>');
	}
}
