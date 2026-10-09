#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "operator.c"

void exercice41(){

    int num1;
    int num2;
    char op;

    printf("Entrez num1 : ");
    scanf("%d", &num1);

    printf("Entrez num2 : ");
    scanf("%d", &num2);

    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    printf("Résultat : %d\n", calcul(num1, num2, op));
}

int main(void){

    int choix;

    printf("TP4\n");
    printf("1 - Exercice 4.1\n");
    //printf("2 - Exercice 4.2\n");
    //printf("3 - Exercice 4.7\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1){
        exercice41();
    } //else if (choix == 2){
        //exercice42();
    //else if (choix == 3){
        //exercice47();}
    else {printf("Choix invalide\n");}

    return 0;
}

