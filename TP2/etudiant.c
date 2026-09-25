#include <stdio.h>

char noms_prenoms[5][50] = { 
    "Martin Alice",
    "Bernard Hugo",
    "Dubois Chloé",
    "Moreau Lucas",
    "Leroy Inès"
};

char adresses[5][100] = {
    "12 rue des Lilas, Paris",
    "8 avenue Victor Hugo, Lyon",
    "25 rue Pasteur, Nantes",
    "4 boulevard de la République, Lille",
    "17 rue de la Gare, Rennes"
};

float notes_module1[5] = {15.5, 12.0, 17.25, 14.0, 16.5};
float notes_module2[5] = {14.0, 13.5, 16.0, 15.25, 12.5};

int main(){

    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d : %s\n", i + 1, noms_prenoms[i]);
        printf("%s\n", adresses[i]);
        printf("%.2f\n", notes_module1[i]);
        printf("%.2f\n", notes_module2[i]);
        printf("\n");
    }

    return 0;
}
