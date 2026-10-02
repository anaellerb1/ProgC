#include <stdio.h>
#include <stdlib.h>

int main(void){
	int tableau[100];
    for(int i = 0; i < 100; i++){
        tableau[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < 100; i++){
        for (int j = i + 1; j < 100; j++){
            if (tableau[i] > tableau[j]){
                int temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }

    printf("Tableau trié :\n-");
    for(int i = 0; i < 100; i++){   
        printf("%d ", tableau[i]);
    }

    int recherche;
    printf("\nEntrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &recherche);

    // Initialise les bornes de la zone de recherche.
    int debut = 0;
    int fin = 99;

    
    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;
        if (tableau[milieu] == recherche) {
            printf("L'entier %d est présent dans le tableau.\n", recherche);
            return 0;
        }

        if (tableau[milieu] < recherche) {
            // La recherche continue dans la moitié droite.
            debut = milieu + 1;
        } else {
            // La recherche continue dans la moitié gauche.
            fin = milieu - 1;
        }
    }
    printf("L'entier %d est absent du tableau.\n", recherche);
    return 0;
}


