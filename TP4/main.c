#include <stdio.h>
#include <stdlib.h>

#include "operator.h"
#include "operator.c"

#include "fichier.h"
#include "fichier.c"


void exercice41(){

    int num1;
    int num2;
    char op;

    printf("Entrez num1 : ");
    scanf("%d", &num1);

    printf("Entrez num2 : ");
    scanf("%d", &num2);

    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    printf("Résultat : %d\n", calcul(num1, num2, op));
}

void exercice42(){

    int choix = 0;
    char nom_de_fichier[100];
    char message[500];

    while (choix != 3){

        printf("\nQue souhaitez-vous faire ?\n");
        printf("1. Lire un fichier\n");
        printf("2. Écrire dans un fichier\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1){
            printf("Entrez le nom du fichier à lire : ");
            scanf("%99s", nom_de_fichier);
            lire_fichier(nom_de_fichier);
        } else if (choix == 2){
            printf("Entrez le nom du fichier dans lequel vous souhaitez écrire : ");
            scanf("%99s", nom_de_fichier);
            printf("Entrez le message à écrire : ");
            scanf(" %499[^\n]", message);
            ecrire_dans_fichier(nom_de_fichier, message);
        } else if (choix == 3){
            printf("Sortie....\n");
        } else {
            printf("Choix invalide\n");
        }
    }
}

int main(void){

    int choix;

    printf("TP4\n");
    printf("1 - Exercice 4.1\n");
    printf("2 - Exercice 4.2\n");
    //printf("3 - Exercice 4.7\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1){
        exercice41();
    } else if (choix == 2){
        exercice42();}
    //else if (choix == 3){
        //exercice47();}
    else {printf("Choix invalide\n");}

    return 0;
}

