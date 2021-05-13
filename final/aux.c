#include "tictac.h"
#include <stdlib.h>
#define X 1
#define O 2

int welcome() {
    int number;
    printf("Hi, You are going to play the 'Tic Tac Toe' game! (El Gato para los compas)\n");
    // I modified the next line
    printf("Write a number:....\n1 for play alone (This doesn't Work)\n2 for play with another person\n3 for check your log (This doesn't Work)\n");
    scanf("%d", &number);
    return number;
}

void reserve_memory() {
    extern int** gato;
    int i;
    gato = (int**)malloc(sizeof(int*));
    for (i = 0; i < 3; i++) {
        gato[i] = (int*)malloc(sizeof(int));
    }
}

void free_memory() {
    extern int** gato;
    int i;
    for (i = 0; i < 3; i++) {
        free(gato[i]);
    }
    free(gato);
}

char print_char(int player) {
    switch (player)
    {
    case X:
        return 'X';
    case O:
        return 'O';
    default:
        return ' ';
    }
    return ' ';
}

void view() {
    extern int** gato;
    int i, j;
    printf("\n   |   |   \n");
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j != 1) {
                printf("%s %c %s", j == 0 ? "": "", print_char(gato[i][j]), j == 2 ? "" : "");
            } else {
                printf("| %c |", print_char(gato[i][j]));
            }
        }
        i != 2 ? printf("\n───┼───┼───\n") : printf("\n   |   |   \n");
    }
    printf("\n");
}


// Basic rules for the game
int play(int* role) {
    char c; 
    int row;
    int counter;
    char column;
    extern int** gato;
    view();
    printf("Write the column with the row: Ex: 'A1'\n");
    //while ( (c = getchar()) != '\n' && c != EOF );
    while((c = getchar()) != EOF && c != '\n') {
        switch (c) {
        default:
            if (counter == 0) {
                row = (c - '0' - 1);
                counter++;
            } else {
                column = (c - '0' - 49);
                counter = 0;
            }
            break;
        }
    }
    if (column >= 0 && column < 3 && row >= 0 && row < 3) {
        printf("%d %d\n", column, row);
        gato[column][row] = *role;
    }
    return 0;
}

int check() {
    return 1;
}

// If the initial case is 1
int play_alone() {
    printf("You selected play alone\n");
    printf("This doesn't work at the moment\n");
}

// If the initial case is 2
int play_with_someone() {
    int role = 1;
    reserve_memory();
    printf("You selected play with another person\n");
    while (check()) {
        if (role == 1) {
            play(&role);
            role = 2;
        } else {
            play(&role);
            role = 1;
        }
    }
    free_memory();
}

// If the initial case is 3
int get_scores() {
    printf("Your scores:\n");
    printf("This doesn't work at the moment\n");
}