#include <stdio.h>

int num1 = 5;
int num2 = 10;
//char op = ['+', '-', '*', '/', '%', '&', '|', '~'];
char op = '&';

int main() {
    int resultat = 0;

    switch (op){
    case '+':
        resultat = num1 + num2;
        break;
    case '-':
        resultat = num1 - num2;
        break;
    case '*':
        resultat = num1 * num2;
        break;
    case '/':
        resultat = num1 / num2;
        break;
    case '&':
        resultat = num1 & num2;
        break;
    case '%':
        resultat = num1 % num2;
        break;
    case '|':
        resultat = num1 | num2;
        break;
    case '~':
        resultat = ~num1;
        break;    
    }
    printf("Le résultat de l'opération %d %c %d est : %d\n", num1, op, num2, resultat);
    return 0;
}