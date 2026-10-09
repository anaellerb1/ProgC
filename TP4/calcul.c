#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[]) {

	/* argv[0] = "./calcule", argv[1] = opérateur, argv[2] = num1, argv[3] = num2 */
	if (argc != 4) {
		printf("Usage : %s <opérateur> <num1> <num2>\n", argv[0]);
		return 1;
	}

	char op = argv[1][0];      /* premier caractère de l'opérateur */
	int num1 = atoi(argv[2]);  /* conversion texte -> entier */
	int num2 = atoi(argv[3]);
	int resultat;

	switch (op) {
		case '+':
			resultat = somme(num1, num2);
			break;
		case '-':
			resultat = difference(num1, num2);
			break;
		case '*':
			resultat = produit(num1, num2);
			break;
		case '/':
			if (num2 == 0) {
				printf("Erreur : division par zéro\n");
				return 1;
			}
			resultat = quotient(num1, num2);
			break;
		case '%':
			if (num2 == 0) {
				printf("Erreur : modulo par zéro\n");
				return 1;
			}
			resultat = modulo(num1, num2);
			break;
		case '&':
			resultat = et(num1, num2);
			break;
		case '|':
			resultat = ou(num1, num2);
			break;
		case '~':
			resultat = negation(num1, num2);
			break;
		default:
			printf("Opérateur inconnu : %s\n", argv[1]);
			return 1;
	}

	printf("Résultat : %d\n", resultat);
	return 0;
}