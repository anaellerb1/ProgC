#include <stdio.h>

void ecrire_fichier(char *nom_fichier,const char *message){
    FILE *fichier = fopen(nom_fichier,"w");

    if (fichier == NULL){
        perror("fopen");
        return;
    }

    fprintf(fichier,"%s",message);
    
    fclose(fichier);
}

int main(void){
    char *message = "Coucou je test la fonction écrire.";
    ecrire_fichier("test.txt",message);
}