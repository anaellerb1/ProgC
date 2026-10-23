#include <stdio.h>

// Sommer des chiffres

int main(void){
    int somme = 0;
    int taille = 100;

    for (int i=0 ; i < taille+1;i++){
        if ((i % 3 == 0 || i % 4 == 0) && i%6 != 0){
            somme += i;
            printf("i = %d, somme = %d\n",i,somme);
    }}

    printf("Résultat = %d\n",somme);
    return 0;


}