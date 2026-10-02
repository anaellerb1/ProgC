#include <stdio.h>
#include <stdlib.h>

int tableau[100];

int main(void){

    int entiers[100];

    for(int i = 0; i < 100; i++){
        entiers[i] = rand() % 1000 + 1;
    }
    
    int max = entiers[0];
    int min = entiers[0];
    for (int i = 1; i < 100; i++){
        if (entiers[i] > max){
            max = entiers[i];
        }
        if (entiers[i] < min){
            min = entiers[i];
        }
    }

    printf("Le plus grand entier est : %d\n", max);
    printf("Le plus petit entier est : %d\n", min);

    return 0;
}