#include <stdio.h>
#include <ctype.h>
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

