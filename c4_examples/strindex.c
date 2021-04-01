#include <stdio.h> // i/o

#define END '\0'

int strindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != END; i++) {
		for (j = i, k = 0; t[k] != END && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == END) {
			return i;
		}
	}
	return -1;
}

int main() {
	char s[] = "Hola, esto es una prueba";
	char t[] = "Prueba";
	int res;

	res = strindex(s, t);
	printf("%d\n", res);
}
