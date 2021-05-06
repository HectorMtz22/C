#include "homework7.h"
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

int read(FILE * file) {
    extern struct data *employee;
    int c;
    int counter;
    char * temp;
    int j;
    while((c = fgetc(file)) != EOF) {
        /*
        switch (c) {
        case ',':
            switch (counter)
            {
            case 0:
                employee->number = temp;
                break;
            case 1:
                employee->name = temp;
                break;
            case 2:
                employee->entry = temp;
                break;
            case 3: 
                employee->exit = temp;
            default:
                break;
            }
            counter++;
            break;
        
        default:
            temp[j++] = c;
        }
        */
    return 0;
    }
}

int empleado(long int timing) {
    int c;
    FILE * log;
    printf("Marcar entrada: 1\n");
    printf("Marcar salida: 2\n");
    
    
    log = fopen("data/log.txt", "a");
    while((c = getchar()) != EOF) {
        switch (c) {
            case 1:
                fprintf(log, "%ld", timing);
                break;
    
            default:
                break;
        }
    }
    
    fclose(log);
    return 1;
}

int administrador() {
    printf("Registrar Nuevo: 1\n");
    return 1;
}