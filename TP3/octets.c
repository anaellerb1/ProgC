#include <stdio.h>

//gcc -Wall -Wextra octets.c 

void afficher_octets(const char *nom, const void *adresse, size_t taille){
    const unsigned char *pointeur = adresse; 

    printf("\nOctets de %s (taille = %zu) :\n",nom, (int)taille);
    for (size_t i = 0; i < taille; i++){ 
        printf( " %02x", pointeur[i]);
    }
    printf("\n");
}

void type_boutiste(void){
    /* indique si votre machine semble utiliser un ordre petit-boutiste 
    ou gros-boutiste pour les entiers*/
    int entier = 1;
    unsigned char *octets = (unsigned char *)&entier;
    if (octets[0] == 1) {
        printf("La machine est petit-boutiste.\n");
    } else {
        printf("La machine est gros-boutiste.\n");  
    }
}


int main(void){

    int Int = 642;
    short Short = 642;
    long int Longint = 642;
    float Float = 642.2f;
    double Double = 642.2;
    long double Longdouble = 642.2L;

    afficher_octets("int", &Int, sizeof(Int));
    afficher_octets("short", &Short, sizeof(Short));
    afficher_octets("long int", &Longint, sizeof(Longint));
    afficher_octets("float", &Float, sizeof(Float));
    afficher_octets("double", &Double, sizeof(Double));
    afficher_octets("long double", &Longdouble, sizeof(Longdouble));

    type_boutiste();
    return 0;
}

/*
Expliquez pourquoi l'affichage des octets peut varier selon 
l'architecture, le compilateur et les options de compilation.

L'affichage peut varier selon l'architecture, car la taille des types et
l'ordre des octets (petit-boutiste ou gros-boutiste) peuvent être différents.
Par exemple, 
    sur Linux 64 bits, long fait 8 octets ; 
    sous Windows 64 bits, il en fait 4.
*/