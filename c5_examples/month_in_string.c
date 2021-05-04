#include <stdio.h>
#include <stdlib.h>

char* month_name(int n) {
    static char* names[] = {
        "Invalid", 
        "January", 
        "February", 
        "March", 
        "April", 
        "May", 
        "June", 
        "July", 
        "August", 
        "September", 
        "October", 
        "November", 
        "December"
    };

    if (n < 0 || n > 12) {
        return names[0];
    } else {
        return names[n];
    }

}

int main(int argc, char* args[]) {
    int number = 0;
    if (argc > 1) {
        number = atoi(args[1]);
    } else {
        printf("Insert a value\n");
        scanf("%d", &number);
    }

    printf("The Month %d is: %s\n", number, month_name(number));

    return 0;
}