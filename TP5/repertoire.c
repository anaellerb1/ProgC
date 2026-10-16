#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "repertoire.h"

void lire_dossier(char *nom_du_repertoire) {
    /* affiche les noms des fichiers et répertoires présents dans nom_du_repertoire */

    DIR *rep = opendir(nom_du_repertoire); 
    if (rep == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(rep)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(rep);
}

void lire_dossier_recursif(const char *nom_du_repertoire) {
    /* Affiche récursivement les fichiers, répertoires et sous-répertoires de nom_du_repertoire */

    DIR *rep = opendir(nom_du_repertoire);
    if (rep == NULL) {
        perror(nom_du_repertoire);
        return;
    }

    // Parcourir les entrées du répertoire
    struct dirent *entree;
    while ((entree = readdir(rep)) != NULL) {
        // "." et ".." sont des répertoires : sans ce test, récursion infinie
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0)
            continue;

        char chemin[512];
        int n = snprintf(chemin, sizeof(chemin), "%s/%s",
                         nom_du_repertoire, entree->d_name);
        if (n < 0 || n >= (int)sizeof(chemin)) {
            fprintf(stderr, "Chemin trop long, ignoré : %s/%s\n",
                    nom_du_repertoire, entree->d_name);
            continue;
        }

        // Récupérer les informations sur l'entrée
        struct stat sf;
        if (stat(chemin, &sf) == -1) {
            perror(chemin);
            continue;
        }

        if (S_ISDIR(sf.st_mode)) {
            printf("%s\n", chemin);
            lire_dossier_recursif(chemin);   // appel récursif
        } else {
            printf("    %s\n", chemin);
        }
    }

    closedir(rep);
}

void lire_dossier_iteratif(const char *nom_du_repertoire) {
    /* Affiche itérativement les fichiers, répertoires et sous-répertoires
     * de nom_du_repertoire, en utilisant une pile de chemins à visiter
     * à la place de la récursion. */

    // Pile dynamique de chemins
    int capacite = 16; 
    int taille = 0;
    char **pile = malloc(capacite * sizeof(char *));
    if (pile == NULL) {
        perror("malloc");
        return;
    }

    // Empiler le répertoire de départ (copie de la chaîne)
    pile[taille] = malloc(strlen(nom_du_repertoire) + 1);
    if (pile[taille] == NULL) {
        perror("malloc");
        free(pile);
        return;
    }
    strcpy(pile[taille], nom_du_repertoire); 
    taille++;

    while (taille > 0) {
        // Dépiler le dernier chemin ajouté
        taille--;
        char *courant = pile[taille];

        DIR *rep = opendir(courant);
        if (rep == NULL) {
            perror(courant);
            free(courant);
            continue;
        }

        struct dirent *entree;
        while ((entree = readdir(rep)) != NULL) {
            // Ignorer "." et ".."
            if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0)
                continue;

            // Construire le chemin complet : courant/entree
            char chemin[512];
            int n = snprintf(chemin, sizeof(chemin), "%s/%s", courant, entree->d_name);
            if (n < 0 || n >= (int)sizeof(chemin)) {
                fprintf(stderr, "Chemin trop long, ignoré : %s/%s\n",
                        courant, entree->d_name);
                continue;
            }

            struct stat sf;
            if (stat(chemin, &sf) == -1) {
                perror(chemin);
                continue;
            }

            if (S_ISDIR(sf.st_mode)) {
                printf("Répertoire : %s\n", chemin);

                // Agrandir la pile si elle est pleine
                if (taille == capacite) {
                    capacite *= 2;
                    char **nouvelle = realloc(pile, capacite * sizeof(char *));
                    if (nouvelle == NULL) {
                        perror("realloc");
                        continue;  
                    }
                    pile = nouvelle;
                }

                // Empiler une copie du chemin 
                pile[taille] = malloc(strlen(chemin) + 1);
                if (pile[taille] == NULL) {
                    perror("malloc");
                    continue;
                }
                strcpy(pile[taille], chemin);
                taille++;
            } else {
                printf("Fichier : %s\n", chemin);
            }
        }

        closedir(rep);
        free(courant);  
    }

    free(pile);
}
int main(int argc, char *argv[]) {
    //lire_dossier(nom_repertoire);        
    //lire_dossier_recursif("."); 
    lire_dossier_iteratif("..");

    return 0;
}