#include <stdio.h>

void lire_fichier(char *nom_fichier){
    FILE *fichier = fopen(nom_fichier,"r");

    if (fichier == NULL){
        perror("fichier vide");
        return;
    }

    int c = fgetc(fichier);
    while(c != EOF){
        printf("%c",c);
        c = getc(fichier);
    }
    printf("\n");

    fclose(fichier);
}


int main(void){
    lire_fichier("test.txt");

}