#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

int convert_to_line(); // Converts single characters to lines
// int ignore_tags(); 
// int check_tag(); 
int print(); // Prints the line w/o the tags
int spacesToUnderscore();
char linea[MAX];

int main() {
	extern char linea[];
	int ignore = 1;
	int p, strong, h1;
	
	p = strong = h1 = 0; // Initialization
	while (convert_to_line() == 0) {

		// I should use switch case 
		if (strstr(linea, "<p>") != NULL) {
			p++;
		}
		if (strstr(linea, "<h1>") != NULL) {
			h1++;
		}
		if (h1 > 0) {
			spacesToUnderscore();
		}
		if (strstr(linea, "</h1") != NULL) {
			h1--;
		}
		if (p > 0) {
			if (strstr(linea, "<strong>") != NULL) {
				strong++;
				spacesToUnderscore();
			} else {
				print();
			}
		}
		if (strstr(linea, "</p>") != NULL) {
			p--;
		}
		if (strstr(linea, "</strong>") != NULL) {
			strong--;
		}
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
			ignore = 1;
		} 
		if (!ignore) {
			printf("%c", linea[i]);
		}
		if (linea[i] == '>') {
			printf("\n");  // New line for all 
			ignore = 0;
		}
	}
}

int spacesToUnderscore() {
	extern char linea[];
	int space;
	int i;
	int ignore = 1;
	int num_max = strlen(linea); // This functions counts the length

	for (i = 0; i < num_max; i++) {
		if (linea[i] == '<') { // Here, we evaluate the char 
			ignore = 1;
		} 
		if (!ignore) {
			if (isspace(linea[i])) {
      space = 1;
    } else {
      if (space)  {
				printf("_"); // Replace the space
				space = 0;   // Reestablecer counter
      }
			printf("%c", linea[i]);
		}
		}
		if (linea[i] == '>') {
			ignore = 0;
		}
	}
  return 0;

}

int convert_to_line() {
  extern char linea[];
  int c, i = 0;
  for (i = 0; i < MAX  && (c = getchar()) != EOF && c != '\n';) {
      linea[i++] = c;
  }
  linea[i] = '\0'; 
	return c == EOF;
}

// These functions were the experiments

/*
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
*/

/*
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
*/
