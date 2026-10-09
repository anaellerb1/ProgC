#include <stdio.h>
#include <string.h>
#include "fichier.h"

#define NB_ETUDIANTS 5

/* Structure reprise de etudiant2.c (TP2) */
struct Etudiant {
	char nom[30];
	char prenom[30];
	char adresse[80];
	float note1;
	float note2;
};

void lire_chaine(char *invite, char *chaine, int taille) {
	printf("%s", invite);
	fgets(chaine, taille, stdin);
	chaine[strlen(chaine) - 1] = '\0';   // enlève le \n à la fin
}

void lire_note(char *invite, float *note) {
	printf("%s", invite);
	scanf("%f", note);
	while (getchar() != '\n');            // vide le \n laissé par scanf
}

int main(void) {
	struct Etudiant etudiants[NB_ETUDIANTS];
	char ligne[200];                      /* une ligne = un étudiant */
	char contenu[NB_ETUDIANTS * 200] = ""; /* tout le fichier */

	for (int i = 0; i < NB_ETUDIANTS; i++) {
		printf("Entrez les détails de l'étudiant.e %d :\n", i + 1);

		lire_chaine("Nom : ", etudiants[i].nom, sizeof etudiants[i].nom);

		lire_chaine("Prénom : ", etudiants[i].prenom, sizeof etudiants[i].prenom);

		lire_chaine("Adresse : ", etudiants[i].adresse, sizeof etudiants[i].adresse);

       	lire_note("Note 1 : ", &etudiants[i].note1);

		lire_note("Note 2 : ", &etudiants[i].note2);
        
		/* Mise en forme de la ligne */
		sprintf(ligne, "%s;%s;%s;%.2f;%.2f\n",
				etudiants[i].nom, etudiants[i].prenom, etudiants[i].adresse,
				etudiants[i].note1, etudiants[i].note2);
		strcat(contenu, ligne);
	}

	/* ecrire_dans_fichier ouvre en mode "w" : on l'appelle une seule fois
	   avec les 5 lignes, sinon chaque appel écraserait le précédent. */
	ecrire_dans_fichier("etudiant.txt", contenu);
	printf("Les détails des étudiants ont été enregistrés dans le fichier etudiant.txt.\n");

	return 0;
}