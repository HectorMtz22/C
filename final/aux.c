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
void play(int* role, int* column, int* row) {
    char c; 
    int counter;
    view();
    printf("Write the column with the row: Ex: 'A1'\n");
    //while ( (c = getchar()) != '\n' && c != EOF );
    while((c = getchar()) != EOF && c != '\n') {
        printf("%c", (c - '0'));
        switch (c) {
        default:
            if (counter == 0) {
                *row = (c - '0' - 1);
                counter = 1;
            } else {
                *column = (c - '0' - 49);
                counter = 0;
            }
            break;
        }
    }
    return;
}

int check() {
    extern int **gato;
    int i, j;

    // Horizontal lines
    for (i = 0; i < 3; i++) {
        if (gato[i][0] == gato[i][1] && gato[i][0] == gato[i][2] && gato[i][0] != 0) {
            return gato[i][0];
        }
    }
 
    // Vertical lines
    for (i = 0; i < 3; i++) {
        if (gato[0][i] == gato[1][i] && gato[0][i] == gato[2][i] && gato[0][i] != 0) {
            return gato[0][i];
        }
    }

    // Diagonal lines
    if (gato[0][0] == gato[1][1] && gato[0][0] == gato[2][2] && gato[0][0] != 0) {
       return gato[0][0];
    }
    if (gato[2][0] == gato[1][1] && gato[2][0] == gato[0][2] && gato[2][0] != 0) {
       return gato[2][0];
    }
    return 0;
}

// If the initial case is 1
int play_alone() {
    printf("You selected play alone\n");
    printf("This doesn't work at the moment\n");
}

// If the initial case is 2
int play_with_someone() {
    int role = X;
    int column;
    int row;
    extern int** gato;
    reserve_memory();
    printf("You selected play with another person\n");
    while (check() == 0) {
        play(&role, &column, &row);
        if (column >= 0 && column < 3 && row >= 0 && row < 3) {
            printf("%d %d\n", column, row);
            if (gato[column][row] != 0) {
                printf("This box isn't available!\n");
            } else {
                gato[column][row] = role;
                role == X ? (role = O) : (role = X);
            }
        }
    }
    view();
    printf("%s Won!\n", role == X ? "X" : "O");
    free_memory();
}

// If the initial case is 3
int get_scores() {
    printf("Your scores:\n");
    printf("This doesn't work at the moment\n");
}