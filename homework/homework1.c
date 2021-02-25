#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

int convert_to_line();
int ignore_tags();
int check_tag();
int print();
int spacesToUnderscore();
char linea[MAX];

int main() {
	extern char linea[];
	int ignore = 1;
	int tag = 0;
	int p, strong, h1;
	p = strong = h1 = 0;
	while (convert_to_line() == 0) {
		if (strstr(linea, "<p>") != NULL) {
			p++;
		}
		if (p > 0) {
			print();
		}
		if (strstr(linea, "</p>") != NULL) {
			p--;
		}
		if (strstr(linea, "<strong>") != NULL) {
			strong++;
		}
		if (strstr(linea, "</strong>") != NULL) {
			strong--;
		}
	}
	return 0;
}

int check_tag() {
	extern char linea[];
	if (strstr(linea, "<p>") != NULL) {
		return 1;
	}
	if (strstr(linea, "</p>") != NULL) {
		return 0;
	}
	return 0;
}

int print() {
	extern char linea[];
	int ignore = 0;
	int i;
	int num_max = strlen(linea);

	for (i = 0; i < num_max; i++) {
		if (linea[i] == '<') {
			if (strstr(linea, "strong") != NULL) {
				spacesToUnderscore();
			}
			ignore = 1;
		} 
		if (!ignore) {
			
			printf("%c", linea[i]);
		}
		if (linea[i] == '>') {
			ignore = 0;
		}
	}
}

int spacesToUnderscore() {
	extern char linea[];
	int space;
	int i;
	for (i = 0; i < MAX ; i++) {
    if (isspace(linea[i])) {
      space = 1;
    } else {
      if (space)  {
				printf("_");
				space = 0;
      }
    printf("%c", linea[i]);
		// putchar(linea[i]);
  	}
	}
  return 0;

}

int ignore_tags() {
	extern char linea[];
	int ignore = 0;
	int i;
	int num_max = strlen(linea);

	for (i = 0; i < num_max; i++) {
		if (linea[i] == '<') {
			ignore = 1;
		} 
		if (!ignore) {
			printf("%c", linea[i]);
		}
		if (linea[i] == '>') {
			ignore = 0;
		}
	}
}

int convert_to_line() {
  extern char linea[];
  int c, i = 0;
  int sc = 0;
  for (i = 0; i < MAX  && (c = getchar()) != EOF && c != '\n';) {
      linea[i++] = c;
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return c == EOF;
}
