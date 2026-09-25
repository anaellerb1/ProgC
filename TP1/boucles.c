#include <stdio.h>

int compteur = 8;

int main(){

    for (int i = 0; i < compteur; i++) { // boucle qui s'exécute tant que i est inférieur à compteur, i++ : incrémente i de 1 à chaque itération
        for (int j = 0; j <= i ; j++) { 
            if (i > 1 && j > 0 && j < i && i < compteur - 1) { 
                printf("#");}
            else {
            printf("*");}
        }
        printf("\n");
    }

    int i = 0;
    while (i < compteur) { 
        int j = 0;
        while (j <= i) {
            if (i > 1 && j > 0 && j < i && i < compteur - 1) { 
                printf("#");}
            else {
            printf("*");}
            j++;
        }
        printf("\n");
        i++; // incrémente i de 1 à chaque itération
    }

    
    

    return 0;
}