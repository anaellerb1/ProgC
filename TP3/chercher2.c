#include <stdio.h>

// gcc -Wall -Wextra chercher2.c

int main(void) {
    const char *phrases[10] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    const char *cherche = "La programmation en C est amusante.";
    int trouve = 0;

    for (int i = 0; i < 10; i++) {
        int k = 0;

        // On avance tant que les caractères sont égaux et que la phrase n'est pas finie
        while (phrases[i][k] != '\0' && phrases[i][k] == cherche[k]) {
            k++;
        }

        // Les phrases sont identiques seulement si les deux se terminent au même endroit
        if (phrases[i][k] == '\0' && cherche[k] == '\0') {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Phrase trouvée\n");
    } else {
        printf("Phrase non trouvée\n");
    }

    return 0;
}