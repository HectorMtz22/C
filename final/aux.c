#include "tictac.h"

int welcome() {
    int number;
    printf("Hi, You are going to play the 'Tic Tac Toe' game! (El Gato para los compas)\n");
    printf("Write a number:....\n1 for play alone\n2 for play with another person\n3 for check your log\n");
    scanf("%d", &number);
    return number;
}