#include <stdio.h>
#include <stdlib.h>

int main(void){

    int entiers[100];

    for(int i = 0; i < 100; i++){
        entiers[i] = rand() % 100 + 1;
    }

    printf("Les entiers générés sont :\n");
    for(int i = 0; i < 100; i++){   
        printf("%d ", entiers[i]);
    }

    printf("\n");

    for (int i = 0; i < 100; i++){
        for (int j = i + 1; j < 100; j++){
            if (entiers[i] > entiers[j]){
                int temp = entiers[i];
                entiers[i] = entiers[j];
                entiers[j] = temp;
            }
        }
    }

    printf("Les entiers triés sont :\n");
    for(int i = 0; i < 100; i++){
        printf("%d ", entiers[i]);  
    }

    printf("\n");



}