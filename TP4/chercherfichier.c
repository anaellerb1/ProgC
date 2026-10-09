#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char nom_fichier[100];
	char phrase[200];
	char ligne[1024];

	/* Nom du fichier : en argument (./chercherfichier fichier.txt) ou demandé */
	if (argc >= 2) {
		strncpy(nom_fichier, argv[1], sizeof nom_fichier - 1);
		nom_fichier[sizeof nom_fichier - 1] = '\0';
	} else {
		printf("Entrez le nom du fichier : ");
		scanf("%99s", nom_fichier);
	}

	printf("Entrez la phrase que vous souhaitez rechercher : ");
	scanf(" %199[^\n]", phrase);          /* la phrase peut contenir des espaces */

	FILE *fichier = fopen(nom_fichier, "r");
	if (fichier == NULL) {
		printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
		return 1;
	}

	printf("\nRésultats de la recherche :\n");

	int numero = 0;       /* numéro de la ligne en cours */
	int trouve = 0;       /* au moins une ligne trouvée ? */
	int longueur = strlen(phrase);

	/* fgets lit le fichier ligne par ligne, jusqu'à la fin (NULL) */
	while (fgets(ligne, sizeof ligne, fichier) != NULL) {
		numero++;
		int compteur = 0;
		char *position = strstr(ligne, phrase);   /* 1re occurrence ou NULL */

		while (position != NULL) {
			compteur++;
			/* on reprend la recherche juste après l'occurrence trouvée */
			position = strstr(position + longueur, phrase);
		}

		if (compteur > 0) {
			printf("Ligne %d, %d fois\n", numero, compteur);
			trouve = 1;
		}
	}

	if (!trouve) {
		printf("Phrase non trouvée.\n");
	}

	fclose(fichier);
	return 0;
}