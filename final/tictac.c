#include "tictac.h" // Include my library

int** gato;

int main() {
    int initial = welcome(); // Principal Menu
    switch (initial) { // According to the welcome menu
    case 1:
        play_alone();
        break;
    case 2:
        play_with_someone();
        break;
    case 3:
        get_scores();
        break;
    
    default:
        // If is not a valid input
        printf("The program didn't recognize your number, it will exit now\n");
        break;
    }

    return 0;
}