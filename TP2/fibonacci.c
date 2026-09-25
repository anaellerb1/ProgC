#include <stdio.h>

int u0 = 0;
int u1 = 1;

int main(){
    int n = 7;
    int un = 0;

    printf("%d %d", u0, u1);

    for (int i = 2; i < n; i++) {
        un = u0 + u1;
        u0 = u1;
        u1 = un;

        printf(" %d", un);
    }
    printf("\n");
    return 0;
}