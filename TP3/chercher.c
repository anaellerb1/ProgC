#include <stdio.h>
#include <stdlib.h>

int main(void){
    int entiers[100];

    for(int i = 0; i < 100; i++){
        entiers[i] = rand() % 100 + 1;
    }

    printf("Tableau :\n-");
    for(int i = 0; i < 100; i++){   
        printf("%d ", entiers[i]);
    }
    printf("\n");


    int recherche;
    printf("Entrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &recherche);

    for(int i = 0; i < 100; i++){
        if(entiers[i] == recherche){
            printf("Résultat : entier présent\n");
            return 0;
        }
    }
    printf("Résultat : entier absent\n");
    
    return 0;
    
}
