#include <stdio.h> // For i/o
#include <string.h> // For basic strlen

void reverse(char s[]) {
	int temp, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++ , j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main() {
	char s[50] ;

	printf("Ingresa una cadena de texto\n");
	scanf("%s", s);
	
	reverse(s);


	printf("El texto invertido es: %s\n", s);

	return 0;
}
