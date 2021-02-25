#include <stdio.h> // Basic i/o
#include <ctype.h> // isspace
#include <string.h> // strstr

#define IN 1
#define OUT 0

#define MAX 80
char linea[MAX];

int saca();

int main() {
	int c;
	int isinside = OUT;
	extern char linea[];
  int ignore = 1;
	int l = 0;
  l = (6 / 2) * (4 / 2); // unrelated demo stuff
  while ((saca()) == 0) { 
    if (strstr(linea, "<p>") != NULL) { // check for substring
      ignore = 0;
			memcpy(linea+0,"   ",3);
    }
    if (!ignore) {
      printf("%s\n", linea);
    }
    if (strstr(linea, "</p>") != NULL) {
      ignore = 1;
			memcpy(linea-4,"    ", 4);
    }
  }
  return 0;

}


int saca() {
  extern char linea[];
  int c, i = 0;
  int sc = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {
    if (c == '/') {
      sc++;
      if (sc == 2) {
	i--;
      }
    } else if (sc < 2) { 
      sc = 0;
    }
    if (sc < 2) {
      linea[i++] = c;
    }
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return c == EOF;
}
