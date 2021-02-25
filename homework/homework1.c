#include <stdio.h> // Basic i/o
#include <ctype.h> // isspace
#include <string.h> // strstr

#define IN 1
#define OUT 0

#define NONE 0
#define P 1
#define STRONG 2

#define MAX 80

char linea[MAX];

int print();
int checkTag(char linea[], int ignore);
int spacesToUnderscore(char linea[]);

int main() {
	int c;
	int isinside = OUT;
	extern char linea[];
  int ignore = 1;
	int tag = 0;
  while ((print()) == 0) { 
		tag = checkTag(linea, ignore);
		if (tag == P) {
      ignore = 0;
		} 
    if (!ignore) {
      printf("%s\n", linea);
    }
    if (tag == NONE) {
      ignore = 1;
    }
		if (tag == STRONG) {
			spacesToUnderscore(linea);
		}
    
  }
  return 0;

}

int checkTag(char linea[], int ignore) {
	if (strstr(linea, "<p>") != NULL) { // check for substring
		return P;
  }
	if (strstr(linea, "<strong>") != NULL) { // check for substring
		return STRONG;
  }
	if (strstr(linea, "</strong>") != NULL) { // check for substring
		return NONE;
  }
	if (!ignore) {
		return P;
	}
	return NONE;
}

int spacesToUnderscore(char linea[]) {
	int space;
	int i;
	for (i = 0; i < MAX ; i++) {
    if (isspace(linea[i])) {
      space = 1;
    } else {
      if (space)  {
				linea[i] = '_';
				space = 0;
      }
    //printf("%c", linea[i]);
		// putchar(linea[i]);
  	}
	}
  return 0;

}

int print() {
  extern char linea[];
  int c, i = 0;
  int sc = 0;
  for (i = 0; i < MAX  && (c = getchar()) != EOF && c != '\n';) {
      linea[i++] = c;
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return c == EOF;
}
