#include <stdio.h>
#include <time.h>
void welcome(struct tm* ntime) {
    printf("Hoy es: %d/%d/%d\n", ntime->tm_mday, ntime->tm_mon+1, ntime->tm_year+1900);
    printf("Son las: %d:%d\n", ntime->tm_hour, ntime->tm_min );
}

int isEmployee() {
    int res = 1;
    printf("Are you an Employee?, write 1 for employee, 0 for admin\n");
    scanf("%d", &res);
    return res;
}