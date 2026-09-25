#include <stdio.h>
#include <math.h>

int main() {
    float rayon = 5.0;
    float aire = M_PI * rayon * rayon;
    float perimetre = 2 * M_PI * rayon;

    printf("Aire du cercle: %.2f\n", aire); // on ajoute %.2f pour afficher le résultat avec 2 décimales
    printf("Périmètre du cercle: %.2f\n", perimetre);

    return 0;
}