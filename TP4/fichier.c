#include <stdio.h>
#include "fichier.h"

void lire_fichier(char *nom_de_fichier){

    FILE *fichier = fopen(nom_de_fichier, "r");

    if (fichier == NULL){
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_de_fichier);
        return;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);

    int c = fgetc(fichier);
    while (c != EOF){
        printf("%c", c);
        c = fgetc(fichier);
    }
    printf("\n");

    fclose(fichier);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message){

    FILE *fichier = fopen(nom_de_fichier, "w");

    if (fichier == NULL){
        printf("Erreur : impossible d'écrire dans le fichier %s\n", nom_de_fichier);
        return;
    }

    fprintf(fichier, "%s", message);
    fclose(fichier);

    printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
}