#include <stdio.h>

int a = 3;
int b = 3;

int main(){

    int resultat = 1;

    for (int i = 0; i < b; i++) { 
        resultat *= a; 
    }

    printf("%d puissance %d = %d\n", a, b, resultat);
    return 0;
}