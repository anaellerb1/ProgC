#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tableauEntiers[10];
float tableauFlottants[10];

int main(){
    srand(time(NULL));

    for (int i = 0; i < 10; i++){
        tableauEntiers[i] = rand() % 100; 
        tableauFlottants[i] = (float)(rand() % 100);
    }

    printf("Tableau d'entiers :\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", tableauEntiers[i]);
    }
    printf("\n");

    printf("Tableau de flottants :\n");
    for (int i = 0; i < 10; i++){
        printf("%.2f ", tableauFlottants[i]);
    }
    printf("\n");

    int *pEntiers = tableauEntiers;
    float *pFlottants = tableauFlottants;

    for (int i = 0; i < 10; i++){
        if (i % 2 == 0) {
            *(pEntiers + i) *= 3;
            *(pFlottants + i) *= 3.0f;
        }
    } 

    printf("Tableau d'entiers après modification :\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", tableauEntiers[i]);
    }
    printf("\n");
    printf("Tableau de flottants après modification :\n");
    for (int i = 0; i < 10; i++){
        printf("%.2f ", tableauFlottants[i]);
    }
    printf("\n");

    return 0;
}