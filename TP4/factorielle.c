#include <stdio.h>

/* Fonction récursive : n! = n * (n-1)!, avec 0! = 1 (cas d'arrêt) */
int factorielle(int num) {
	if (num == 0) {
		printf("fact(0): 1\n");
		return 1;
	} else {
		int valeur = num * factorielle(num - 1);   /* appel récursif */
		printf("fact(%d): %d\n", num, valeur);
		return valeur;
	}
}

int main(void) {
	int valeurs[] = {0, 1, 3, 5, 7, 10};
	int nb = sizeof valeurs / sizeof valeurs[0];   /* nombre de valeurs à tester */

	for (int i = 0; i < nb; i++) {
		int n = valeurs[i];
		printf("--- Calcul de %d! ---\n", n);
		printf("Résultat : %d! = %d\n\n", n, factorielle(n));
	}

	return 0;
}