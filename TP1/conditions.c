#include <stdio.h>
int somme = 0;

int main(){
    for (int i = 1; i <= 1000; i++) {
        if ( i%5 == 0 || i%7 == 0) { // && : et logique, || : ou logique, ! : non logique
            somme += i;
        }
        if (i%11 == 0) {
            continue;
        }
        if (somme > 5000) {
            break;
        }
    }

    printf("La somme finale est : %d\n", somme);
    return 0;
}