#include <stdio.h>

int a = 3;
int b = 8;

int main(){
    int calcul = a+b;
    printf("a + b = %d\n", calcul); //%d : affichage d'un entier

    int soustraction = a-b;
    printf("a - b = %d\n", soustraction);

    int multiplication = a*b;
    printf("a * b = %d\n", multiplication);

    float division = (float)a/b; // (float) permet de convertir a en float pour obtenir un résultat décimal
    printf("a / b = %f\n", division);

    float modulo = a%b; 
    printf("a %% b = %f\n", modulo); 

    if (a == b) {
        printf("a est égal à b\n");
    } else if (a>b) {
        printf("a est supérieur à b\n");
    } else {
        printf("a est inférieur à b\n");
    }

    return 0;
}
