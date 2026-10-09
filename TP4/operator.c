#include "operator.h"
#include <stdio.h>

int somme(int num1, int num2){
    return num1 + num2;
}

int difference(int num1, int num2){
    return num1 - num2;
}

int produit(int num1, int num2){
    return num1 * num2;
}

int quotient(int num1, int num2){
    return num1 / num2;
}

int modulo(int num1, int num2){
    return num1 % num2;
}

int et(int num1, int num2){
    return num1 & num2;
}

int ou(int num1, int num2){
    return num1 | num2;
}

int negation(int num1, int num2){
    num2 = 0; 
    return ~num1 + num2;
}

// choisit la bonne fonction selon l'opérateur op
int calcul(int num1, int num2, char op){

    int resultat = 0;

    switch (op){
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
            if (num2 == 0){
                printf("Erreur : division par zéro\n");
            } else {
                resultat = quotient(num1, num2);
            }
            break;
        case '%':
            if (num2 == 0){
                printf("Erreur : modulo par zéro\n");
            } else {
                resultat = modulo(num1, num2);
            }
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
            printf("Opérateur inconnu\n");
    }

    return resultat;
}