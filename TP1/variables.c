#include <stdio.h>

int main() {
    char c = 'A';
    short s = 10;
    signed int i = 100;
    unsigned int ui = 100;
    long int li = 1000;
    long long int lli = 10000;
    float f = 3.14f;
    double d = 3.14159;
    long double ld = 3.14159265358979323846L;

    // afficher les valeurs
    printf("char: %c\n", c);
    printf("short: %d\n", s);
    printf("signed int: %d\n", i);
    printf("unsigned int: %u\n", ui);
    printf("long int: %ld\n", li);
    printf("long long int: %lld\n", lli);
    printf("float: %f\n", f);
    printf("double: %lf\n", d);
    printf("long double: %Lf\n", ld);

    return 0;
}