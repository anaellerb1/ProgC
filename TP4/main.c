#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operator.h"
#include "operator.c"

#include "fichier.h"
#include "fichier.c"

#include "liste.h"
#include "liste.c"

struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[80];
    float note1;
    float note2;
};


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

void exercice43(){

    struct Etudiant etudiants[5];
    char ligne[200];
    char contenu[1000] = "";

    for (int i = 0; i < 5; i++){
        printf("Entrez les détails de l'étudiant.e %d :\n", i + 1);

        printf("Nom : ");
        scanf(" %29[^\n]", etudiants[i].nom);

        printf("Prénom : ");
        scanf(" %29[^\n]", etudiants[i].prenom);

        printf("Adresse : ");
        scanf(" %79[^\n]", etudiants[i].adresse);

        printf("Note 1 : ");
        scanf("%f", &etudiants[i].note1);

        printf("Note 2 : ");
        scanf("%f", &etudiants[i].note2);
        printf("\n");

        sprintf(ligne, "%s;%s;%s;%.2f;%.2f\n",
                etudiants[i].nom, etudiants[i].prenom, etudiants[i].adresse,
                etudiants[i].note1, etudiants[i].note2);
        strcat(contenu, ligne);
    }

    ecrire_dans_fichier("etudiant.txt", contenu);
    printf("Les détails des étudiants ont été enregistrés dans le fichier etudiant.txt.\n");
}


void exercice47(){
 
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
 
    /* 10 couleurs {rouge, vert, bleu, alpha} */
    struct couleur couleurs[10] = {
        {0xFF, 0x00, 0x00, 0xFF},   /* rouge */
        {0x00, 0xFF, 0x00, 0xFF},   /* vert */
        {0x00, 0x00, 0xFF, 0xFF},   /* bleu */
        {0xFF, 0xFF, 0x00, 0xFF},   /* jaune */
        {0x00, 0xFF, 0xFF, 0xFF},   /* cyan */
        {0xFF, 0x00, 0xFF, 0xFF},   /* magenta */
        {0xFF, 0xFF, 0xFF, 0xFF},   /* blanc */
        {0x00, 0x00, 0x00, 0xFF},   /* noir */
        {0xFF, 0xA5, 0x00, 0xFF},   /* orange */
        {0x80, 0x80, 0x80, 0xFF}    /* gris */
    };
 
    for (int i = 0; i < 10; i++){
        insertion(&couleurs[i], &ma_liste);
    }
 
    printf("Liste des couleurs :\n");
    parcours(&ma_liste);
 
    liberer_liste(&ma_liste);
}

int main(void){

    int choix;

    printf("TP4\n");
    printf("1 - Exercice 4.1\n");
    printf("2 - Exercice 4.2\n");
    printf("3 - Exercice 4.7\n");
    printf("4 - Exercice 4.7\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1){
        exercice41();
    } else if (choix == 2){
        exercice42();}
    else if (choix == 3){
        exercice43();
    } else if (choix == 4){
        exercice47();
    } else {printf("Choix invalide\n");}

    return 0;
}

