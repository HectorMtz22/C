#include <stdio.h> // i/o

int main() {
	int i, j, k;
	char* start = "Hey Jude";

	char* dont = "don't";
	char* dont_1[3] = {
		"make it bad, take a sad song and make it better", 
		"be afraid, you were made to go out and get her", 
		"let me down, you have found her, now go and get her"
	};

	char* remember = "remember to";
	char* remember_1[2] = {
		"let her into your heart",
		"let her under your skin"
	};

	char* then = "then you";
	char* then_1[2] = {
		"can start to make it better",
		"begin to make it better"
	};

	char* final = "better, better, better, better, oh yeah!";

	// Computations
	
	for (i = 0; i < 2; i++) {
		printf("%s ", start);
		printf("%s ", dont);
		printf("%s\n", dont_1[i]);
		printf("%s ", remember);
		printf("%s\n", remember_1[i]);
		printf("%s ", then);
		printf("%s\n", then_1[i]);
	}
	printf("%s\n", final);

	return 0;
}
