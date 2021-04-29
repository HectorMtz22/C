#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"

int convert_to_line(char username[], char password[]) {
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
			default:
				if (c == '\n') {
					i = j = k = l = 0;
					break;
				}
		}
  }
	username[k] = '\0';
	password[l] = '\0';
	return c == EOF;
}

node* insert(char user[], char pass[], node* pos, int d) {
	node* temp;
	if (pos == NULL) {
		pos = (node*)malloc(sizeof(node));
		pos->user = user;
		pos->pass = pass;
		pos->depth = d;
	} else {
		if (pos->user == user) {
			printf("aiwei\n");
				
		} else if (pos->user > user) {
			temp = insert(user, pass, pos->leftChild,  (d + 1));
			if (pos->leftChild == NULL) {
				pos->leftChild = temp;
			}
		} else {
			temp = insert(user, pass, pos->rightChild, (d + 1));
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
		printf("%c %s %s %c\n", prefix, pos->user, pos->pass, suffix);
		show(pos->leftChild, '<');
		show(pos->rightChild, '>');
	}
	return;
}
