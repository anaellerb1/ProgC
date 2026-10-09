#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* Une liste vide : pas de premier maillon */
void init_liste(struct liste_couleurs *liste) {
	liste->tete = NULL;
}

/* Ajoute une copie de la couleur à la fin de la liste */
void insertion(struct couleur *c, struct liste_couleurs *liste) {
	struct element *nouveau = malloc(sizeof(struct element));
	if (nouveau == NULL) {
		printf("Erreur : allocation mémoire impossible\n");
		return;
	}
	nouveau->couleur = *c;       /* on copie la couleur dans le maillon */
	nouveau->suivant = NULL;     /* ce sera le dernier maillon */

	if (liste->tete == NULL) {   /* liste vide : il devient le premier */
		liste->tete = nouveau;
	} else {                     /* sinon on va jusqu'au dernier maillon */
		struct element *courant = liste->tete;
		while (courant->suivant != NULL) {
			courant = courant->suivant;
		}
		courant->suivant = nouveau;
	}
}

/* Affiche toutes les couleurs, du premier au dernier maillon */
void parcours(struct liste_couleurs *liste) {
	struct element *courant = liste->tete;
	int i = 1;
	while (courant != NULL) {
		printf("Couleur %d : R=0x%02X G=0x%02X B=0x%02X A=0x%02X\n", i,
			   courant->couleur.r, courant->couleur.g,
			   courant->couleur.b, courant->couleur.a);
		courant = courant->suivant;
		i++;
	}
}

/* Libère la mémoire de tous les maillons (chaque malloc doit avoir son free) */
void liberer_liste(struct liste_couleurs *liste) {
	struct element *courant = liste->tete;
	while (courant != NULL) {
		struct element *suivant = courant->suivant;
		free(courant);
		courant = suivant;
	}
	liste->tete = NULL;
}