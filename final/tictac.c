#include "tictac.h"

int main() {
    int initial = welcome();
    switch (initial) {
    case 1:
        printf("You selected play alone\n");
        break;
    case 2:
        printf("You selected play alone\n");
        break;
    case 3:
        printf("Your scores:\n");
        break;
    
    default:
        printf("The program didn't recognize your number, it will exit now\n");
        break;
    }

    return 0;
}