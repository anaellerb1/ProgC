#include <stdio.h>

int n = 5;
int i,j;

int main(void) {
    for (i=1; i<=n; i++) {
        for (j=1; j<=n-i; j++) { // de 1 à n-i pour afficher les espaces avant les chiffres
            printf(" ");
        }

        for (j=1; j<=i; j++) { // de 1 à i pour afficher les chiffres
            printf("%d", j);
        }

        for (j=i-1; j>=1; j--) { //le j-- permet de 
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}