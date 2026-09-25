#include <stdio.h>

struct RGBA {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

struct RGBA couleurs[10] = {
    { .R = 0xef, .G = 0x78, .B = 0x12, .A = 0xff },
    { .R = 0x2c, .G = 0xc8, .B = 0x64, .A = 0xff },
    { .R = 0xff, .G = 0x00, .B = 0x00, .A = 0xff },
    { .R = 0x00, .G = 0xff, .B = 0x00, .A = 0xff },
    { .R = 0x00, .G = 0x00, .B = 0xff, .A = 0xff },
    { .R = 0xff, .G = 0xff, .B = 0x00, .A = 0xff },
    { .R = 0xff, .G = 0x00, .B = 0xff, .A = 0xff },
    { .R = 0x00, .G = 0xff, .B = 0xff, .A = 0xff },
    { .R = 0x80, .G = 0x80, .B = 0x80, .A = 0xff },
    { .R = 0xff, .G = 0xff, .B = 0xff, .A = 0xff }
};

int main(){
    for (int i = 0; i < 10; i++) {
        printf("Couleur n°%d :\n", i + 1);
        printf("R: %u| ", couleurs[i].R);
        printf("G: %u| ", couleurs[i].G);
        printf("B: %u| ", couleurs[i].B);
        printf("A: %u\n", couleurs[i].A);
    }

    return 0;
}