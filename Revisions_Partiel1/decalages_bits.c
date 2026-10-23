#include <stdio.h>

void binaire(int n) {
    if (n > 1) {
        binaire(n / 2);     // on traite d'abord le reste du nombre
    }
    printf("%d", n % 2);    // puis on affiche le dernier bit
}





int main(void) {
    binaire(5);
    printf("\n");
    return 0;
}