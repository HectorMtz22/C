#include "tictac.h"
#include <time.h>
#define X 1
#define O 2

int welcome() {
    int number;
    printf("Hi, You are going to play the 'Tic Tac Toe' game! (El Gato para los compas)\n");
    // I modified the next line
    printf("Write a number:....\n1 for play alone\n2 for play with another person\n3 for check your log\n");
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
    printf("\n  A | B | C \n");
    printf("    |   |   \n");
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j == 0) {
                printf("%d %c ", i + 1, print_char(gato[i][j]));
           
            } else if (j == 1) {
                printf("| %c |", print_char(gato[i][j]));
            } else {
                printf(" %c ", print_char(gato[i][j]));
            }
        }
        i != 2 ? printf("\n ───┼───┼───\n") : printf("\n    |   |   \n");
    }
    printf("\n");
}

void pushWinner(int players, int role) {
    char temp1[10];
    char temp2[10];
    long int tp = time(0);
    FILE * archive = fopen("results.txt", "a");
    if (players == 2) {
        printf("Name of the winner: \n");
        scanf("%s", temp1);
        printf("Name of the looser: \n");
        scanf("%s", temp2);

        fprintf(archive, "%s %s %ld\n", temp1, temp2, time(&tp));
        fclose(archive);

        return;

    } else {
        printf("Name of the player: \n");
        scanf("%s", temp1);
        fprintf(archive, "%s %s %ld\n", role == X ? "CPU" : temp1, role == O ? "CPU" : temp1, time(&tp));
        fclose(archive);
        return;


    }
    
    return;
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
    int role = X;
    int column;
    int row;
    extern int** gato;
    reserve_memory();
    printf("You selected play alone\n");
    srand(time(0));
    while (check() == 0) {
        if (role == X) {
            column = rand() % 3;
            row = rand() % 3;
        } else {
            play(&role, &column, &row);
        }
        if (column >= 0 && column <= 3 && row >= 0 && row <= 3) {
            if (gato[row][column] != 0) {
                if (role == O) {
                    printf("This box isn't available!\n");
                }
            } else {
                gato[row][column] = role;
                role == X ? (role = O) : (role = X); // Change the role
            }
        }
    }
    // When someone wins
    view();
    role == X ? (role = O) : (role = X); // Change the role again for correct results
    printf("%s Won!\n", role == X ? "X" : "O"); // Variable role is inverted for line 141
    pushWinner(1, role);
    free_memory();
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
        if (column >= 0 && column <= 3 && row >= 0 && row <= 3) {
            if (gato[row][column] != 0) {
                printf("This box isn't available!\n");
            } else {
                gato[row][column] = role;
                role == X ? (role = O) : (role = X); // Change the role
            }
        }
    }
    // When someone wins
    view();
    printf("%s Won!\n", role == X ? "O" : "X"); // Variable role is inverted for line 141
    pushWinner(2, role);
    free_memory();
}

// If the initial case is 3
int get_scores() {
    printf("Your scores:\n");
    printf("This doesn't work at the moment\n");
}