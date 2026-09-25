#include <stdio.h>

char chaine1[] = "Marie mange";
char chaine2[] = "des pâtes";
char chaine3[sizeof chaine1+sizeof chaine2-1];

int main(){

    int compteur = 0;

    int i = 0;

    //chaine 1
    for (i = 0; chaine1[i] != '\0'; i++) {
        chaine3[compteur] = chaine1[i];
        compteur++;
    }

    //espace
    chaine3[compteur] = ' ';
    compteur++;

    //chaine 2
    for (i = 0; chaine2[i] != '\0'; i++) {
        chaine3[compteur] = chaine2[i];
        compteur++;
    }

    printf("'%s' compte %d caractères.\n", chaine3,compteur);
    return 0;
}

