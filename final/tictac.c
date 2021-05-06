#include "tictac.h"

int main() {
    int initial = welcome();
    switch (initial) {
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
        printf("The program didn't recognize your number, it will exit now\n");
        break;
    }

    return 0;
}