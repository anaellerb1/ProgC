#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -Wextra couleur_compteur.c

struct couleur {
    unsigned char r, g, b, a;
};

struct couleur_compte {
    struct couleur c;
    int nb;
};

int main(void) {
    struct couleur palette[3] = {
        {0xff, 0x23, 0x23, 0x45},
        {0xff, 0x00, 0x23, 0x12},
        {0x00, 0x80, 0xff, 0xff}
    };

    struct couleur couleurs[100];
    struct couleur_compte distinctes[100];
    int nb_distinctes = 0;

    // Remplissage : chaque case reçoit une couleur de la palette au hasard
    for (int i = 0; i < 100; i++) {
        couleurs[i] = palette[rand() % 3];
    }

    // Comptage
    for (int i = 0; i < 100; i++) {
        int trouve = 0;

        for (int j = 0; j < nb_distinctes; j++) {
            if (couleurs[i].r == distinctes[j].c.r &&
                couleurs[i].g == distinctes[j].c.g &&
                couleurs[i].b == distinctes[j].c.b &&
                couleurs[i].a == distinctes[j].c.a) {
                distinctes[j].nb++;
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            distinctes[nb_distinctes].c = couleurs[i];
            distinctes[nb_distinctes].nb = 1;
            nb_distinctes++;
        }
    }

    // Affichage
    for (int j = 0; j < nb_distinctes; j++) {
        printf("0x%02x 0x%02x 0x%02x 0x%02x : %d\n",
               distinctes[j].c.r, distinctes[j].c.g,
               distinctes[j].c.b, distinctes[j].c.a,
               distinctes[j].nb);
    }

    return 0;
}