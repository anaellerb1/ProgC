#include <stdio.h>
#include <dirent.h>

void lire_dossier(char *nom_dossier){
    DIR *dossier = opendir(nom_dossier);

    if (dossier == NULL){
        perror("Opendir");
        return;
    }

    struct dirent *entree;
    while ((entree=readdir(dossier)) != NULL){
        printf("%s\n",entree -> d_name);
    }
    closedir(dossier);
}

int main(void){
    lire_dossier(".");

}