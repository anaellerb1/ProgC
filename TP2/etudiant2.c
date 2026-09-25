#include <stdio.h>
#include <string.h>

struct Etudiant {
	char nom[30];
	char prenom[30];
	char adresse[80];
	float note1;
	float note2;
};

int main(void) {
	struct Etudiant etudiants[5];
	char noms[5][30] = {
		"Martin", "Bernard", "Dubois", "Moreau", "Leroy"
	};
	char prenoms[5][30] = {
		"Alice", "Hugo", "Chloé", "Lucas", "Inès"
	};
	char adresses[5][100] = {
		"12 rue des Lilas, Paris", "8 avenue Victor Hugo, Lyon",
		"25 rue Pasteur, Nantes", "4 boulevard de la République, Lille",
		"17 rue de la Gare, Rennes"
	};
	float notes_module1[5] = {15.5, 12.0, 17.25, 14.0, 16.5};
	float notes_module2[5] = {14.0, 13.5, 16.0, 15.25, 12.5};

	for (int i = 0; i < 5; i++) {
		strcpy(etudiants[i].nom, noms[i]);
		strcpy(etudiants[i].prenom, prenoms[i]);
		strcpy(etudiants[i].adresse, adresses[i]);
		etudiants[i].note1 = notes_module1[i];
		etudiants[i].note2 = notes_module2[i];
    }
	for (int i = 0; i < 5; i++) {
		printf("Etudiant %d :\n", i + 1);
		printf("Nom : %s\n", etudiants[i].nom);
		printf("Prenom : %s\n", etudiants[i].prenom);
		printf("Adresse : %s\n", etudiants[i].adresse);
		printf("Note 1 : %.2f\nNote 2 : %.2f\n\n",
			   etudiants[i].note1, etudiants[i].note2);
	}

	return 0;
}
