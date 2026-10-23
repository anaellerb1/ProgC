#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 20
#define VAL_MAX 20

int main (void){
    int tableau[TAILLE];
    int *ptr_tab = tableau;
    int n = 5;

    srand(time(NULL));

    for (int i = 0 ; i < TAILLE ; i++ ){
        tableau[i] = rand() % (VAL_MAX + 1);
        //printf("%d ",tableau[i]);
    }

    int n_fois = 0;
    for (int i = 0 ; i < TAILLE ; i++){
        if (*(ptr_tab + i) == n) n_fois += 1;
    }
    printf("\nLe nombre %d a été présent %d fois.\n",n,n_fois);
}