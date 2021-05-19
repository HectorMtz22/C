#include "tictac.h" // The necessary functions
#include <time.h> // This function only need to be here
// Define role players
#define X 1
#define O 2

// This is the funtion that prints the menu
int welcome() {
    int number;
    printf("Hi, You are going to play the 'Tic Tac Toe' game! (El Gato para los compas)\n");
    // I modified the next line
    printf("Write a number:....\n1 for play alone\n2 for play with another person\n3 for check your log\n");
    scanf("%d", &number);
    return number;
}

// This function reserves the memory of the matrix called 'gato'
void reserve_memory() {
    extern int** gato; // We call the gato matrix
    int i;
    gato = (int**)malloc(sizeof(int*)); // We allocate the memory of the columns
    for (i = 0; i < 3; i++) {
        gato[i] = (int*)malloc(sizeof(int)); // We allocate the memory of the rows 
    }
}

// This function free the memory of the matrix called 'gato'
void free_memory() {
    extern int** gato; // We call the gato matrix
    int i;
    for (i = 0; i < 3; i++) {
        free(gato[i]); // We Destroy the gato rows
    }
    free(gato); // We Destroy the gato columns 
}

// This function is used for print beautifully our X and O 
char print_char(int player) {
    switch (player) { // Depends on the role player
    case X:
        return 'X';
    case O:
        return 'O';
    default:
        return ' ';
    }
    return ' ';
}

// This prints beautifully our matrix called 'gato'
void view() {
    extern int** gato;
    int i, j;
    // Printing stuff
    printf("\n  A   B   C \n");
    printf("    │   │   \n");
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j == 0) { // Row 1
                printf("%d %c ", i + 1, print_char(gato[i][j]));
           
            } else if (j == 1) { // Row 2
                printf("│ %c │", print_char(gato[i][j]));
            } else {    // Row 3
                printf(" %c ", print_char(gato[i][j]));
            }
        }
        // The Intersections
        i != 2 ? printf("\n ───┼───┼───\n") : printf("\n    │   │   \n");
    }
    // For an aesthetic view 
    printf("\n");
}

// This append the log on the results.txt file 
void pushWinner(int players, int role) {
    char temp1[10]; // For 1 player
    char temp2[10]; // For the other player
    long int tp = time(0); // Timestamp
    FILE * archive = fopen("results.txt", "a"); // Archive
    if (players == 2) { // When you are playing in multiplayer
        printf("Name of the winner: \n");
        scanf("%s", temp1);
        printf("Name of the looser: \n");
        scanf("%s", temp2);

        // This prints first the winner, next the looser and the timestamp
        fprintf(archive, "%s %s %ld\n", temp1, temp2, time(&tp));
        fclose(archive); // Close archive

        return;

    } else { // When you are playing in singleplayer
        // Only one player
        printf("Name of the player: \n");
        scanf("%s", temp1);

        // This prints first the winner, next the looser and the timestamp
        fprintf(archive, "%s %s %ld\n", role == X ? "CPU" : temp1, role == O ? "CPU" : temp1, time(&tp));
        fclose(archive); // Close archive
        return;


    }
    
    return;
}

// Basic rules for the game
void play(int* role, int* column, int* row) {
    char c; 
    int counter;
    view(); // Print matrix
    printf("Write the column with the row: Ex: 'A1'\n");
    // Loop for capture the input 'A1'
    while((c = getchar()) != EOF && c != '\n') {
        printf("%c", (c - '0'));
        switch (c) {
        default:
            if (counter == 0) {
                *row = (c - '0' - 1); // To int and -1 because our matrix begin at 0
                counter = 1;
            } else {
                *column = (c - '0' - 49); // To int and -49 in ASCII code (This is the alpha part)
                counter = 0;
            }
            break;
        }
    }
    return;
}

// Check if someone wins
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
    int role = O; // Initialize role player
    int column;
    int row;
    extern int** gato;
    reserve_memory(); // This comment is redundant, it reserves the memory
    printf("You selected play alone\n");
    srand(time(0)); // This is the "CPU intelligence"
    while (check() == 0) { // If someone doesn't win yet
        if (role == X) { // If is the turn of the CPU
            // Randomize numbers
            column = rand() % 3; 
            row = rand() % 3;
        } else {
            play(&role, &column, &row); // Execute the corresponding function for play
        }
        if (column >= 0 && column <= 3 && row >= 0 && row <= 3) { // If is a valid parameter
            if (gato[row][column] != 0) { // If this element is available
                if (role == O) { // If you are playing in the role
                    printf("This box isn't available!\n");
                } // If is the computer, skip the print
            } else {
                gato[row][column] = role; // We edit the gato matrix with the role
                role == X ? (role = O) : (role = X); // Change the role
            }
        }
    }
    // When someone wins
    view(); // Print matrix
    role == X ? (role = O) : (role = X); // Change the role again for correct results
    printf("%s Won!\n", role == X ? "X" : "O"); // Variable role is inverted for line 141
    pushWinner(1, role); // Comment redundant, the first thing is the number of players
    free_memory(); // Free memory
}

// If the initial case is 2
int play_with_someone() {
    int role = X;
    int column;
    int row;
    extern int** gato;
    reserve_memory();
    printf("You selected play with another person\n");
    while (check() == 0) { // If someone doesn't win yet
        play(&role, &column, &row); // The magic stuff of playing
        if (column >= 0 && column <= 3 && row >= 0 && row <= 3) { // If is a valid parameter
            if (gato[row][column] != 0) { // If the number is available
                printf("This box isn't available!\n");
            } else {
                gato[row][column] = role; // Edit the number for the role
                role == X ? (role = O) : (role = X); // Change the role
            }
        }
    }
    // When someone wins
    view(); // Print
    printf("%s Won!\n", role == X ? "O" : "X"); // Variable role is inverted for line 212 
    pushWinner(2, role); // 2 players in this game, and the role of the winner
    free_memory(); // Free the memory
}

// If the initial case is 3
int get_scores() {
    char winner[10];
    char looser[10];
    long int timestamp; // For storing the integer
    char ch;
    int i = 0;
    struct tm* timeToPrint; // New variable to print date and hour
    printf("Your scores:\n");
    FILE * archive = fopen("results.txt", "r"); // Open the document

    // If the document doesn't exist
    if (archive == NULL) {
        printf("We have a problem reading this file\n");
        return 1;
    }

    // Read character by character and check for new line
    while((ch=fgetc(archive))!=EOF) { // If it contain data
        i++; // Counter for lines
        fscanf(archive, "%s %s %ld\n", winner, looser, &timestamp); // Scan the line of the document
        timeToPrint = localtime(&timestamp); // Convert timestamp to a struct tm* for print date and hour
        printf("N° %d\n", i); // Prints the number of record
        printf("Winner! %c%s\nLooser! %s \n", ch, winner, looser); // Prints the Winner and the Looser
        printf("Game played %d/%d/%d at %d:%d\n\n", timeToPrint->tm_mday, timeToPrint->tm_mon + 1, timeToPrint->tm_year + 1900, timeToPrint->tm_hour, timeToPrint->tm_min);
    }
    printf("There are %d records in this text file\n", i); // Print the total records
    fclose(archive); // Close document
}