#include <stdio.h>
#include <stdlib.h>

// Exercice 4.1 : somme et moyenne
void exercice41(){
    int n;
    int valeur;
    int somme = 0;

    printf("Combien de valeurs ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Valeur : ");
        scanf("%d", &valeur);
        somme = somme + valeur;
    }

    float moyenne = (float) somme / n;

    printf("La somme est : %d\n", somme);
    printf("La moyenne est : %.2f\n", moyenne);
}

// Exercice 4.2 : plus grande valeur
void exercice42(){
    int n;
    int valeur;
    int max;

    printf("Combien de valeurs ? ");
    scanf("%d", &n);

    printf("Valeur : ");
    scanf("%d", &max);

    for (int i = 1; i < n; i++){
        printf("Valeur : ");
        scanf("%d", &valeur);
        if (valeur > max){
            max = valeur;
        }
    }

    printf("La plus grande valeur est : %d\n", max);
}

// Exercice 4.7 : tri par ordre croissant
void exercice47(){
    int n;
    int tableau[100];

    printf("Combien de valeurs (max 100) ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Valeur : ");
        scanf("%d", &tableau[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (tableau[i] > tableau[j]){
                int temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }

    printf("Les valeurs triées sont :\n");
    for (int i = 0; i < n; i++){
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

int main(void){

    int choix;

    printf("TP4\n");
    printf("1 - Exercice 4.1\n");
    printf("2 - Exercice 4.2\n");
    printf("3 - Exercice 4.7\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1){
        exercice41();
    } else if (choix == 2){
        exercice42();
    } else if (choix == 3){
        exercice47();
    } else {
        printf("Choix invalide\n");
    }

    return 0;
}