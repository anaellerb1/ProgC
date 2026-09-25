#include <stdio.h> // en-têtes(headers)
#include <stdlib.h> // pour malloc, calloc et free

int main() {

    int *tab = calloc(400, sizeof(int));

    if (tab == NULL) {
        perror("Erreur d'allocation avec calloc");
        return -1;
    }

    // Utilisation de la mémoire allouée
    for (int i = 0; i < 400; i++) { // i++ : sert à incrémenter la variable i de 1 à chaque itération
        tab[i] = i; // Remplir le tableau avec des entiers
    }   
   

    for (int i = 0; i < 400; i++) {  
        printf("%d ", tab[i]); // Affichage des valeurs du tableau
    }   

    printf("\n"); 
    free(tab); // libération de mémoire
    tab = NULL; 

    return 0;
}