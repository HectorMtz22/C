#include "tictac.h"

int welcome() {
    int number;
    printf("Hi, You are going to play the 'Tic Tac Toe' game! (El Gato para los compas)\n");
    printf("Write a number:....\n1 for play alone\n2 for play with another person\n3 for check your log\n");
    scanf("%d", &number);
    return number;
}

// Basic rules for the game
int play() {

}


// If the initial case is 1
int play_alone() {
    printf("You selected play alone\n");
}

// If the initial case is 2
int play_with_someone() {
    printf("You selected play with another person\n");
}

// If the initial case is 3
int get_scores() {
    printf("Your scores:\n");
}