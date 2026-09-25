#include <stdio.h>
#include <stdint.h>
#include <string.h>

//Réutilisez les variables de différents types de base 
char c_value = 'A';
short s_value = 10;
signed int i_value = 100;
unsigned int ui_value = 100;
long int li_value = 1000;
long long int lli_value = 10000;
float f_value = 1.0f;
double d_value = 3.14159;
long double ld_value = 3.14159265358979323846L;

// Déclaration des pointeurs
char *c = &c_value;
short *s = &s_value;
signed int *i = &i_value;
unsigned int *ui = &ui_value;
long int *li = &li_value;
long long int *lli = &lli_value;
float *f = &f_value;
double *d = &d_value;
long double *ld = &ld_value;

/* 
Un pointeur stocke l'adresse mémoire d'une variable.
& obtient une adresse et * accède à la valeur à cette adresse.

Pour pouvoir acceder à l'adresse du pointeur, il faut utiliser le cast (void *) cad que l'on convertit le type du pointeur en un pointeur vers void. 
Cela permet d'afficher l'adresse mémoire de manière générique, sans se soucier du type de données pointé.

*/


int main(void){
	printf("c_value   : adresse = %p, valeur = %08X\n", (void *)c, *c);
	printf("s_value   : adresse = %p, valeur = %08X\n", (void *)s, *s);
	printf("i_value   : adresse = %p, valeur = %08X\n", (void *)i, *i);
	printf("ui_value  : adresse = %p, valeur = %08X\n", (void *)ui, *ui);
	printf("li_value  : adresse = %p, valeur = %08lX\n", (void *)li, *li);
	printf("lli_value : adresse = %p, valeur = %08llX\n", (void *)lli, *lli);
	printf("f_value   : adresse = %p, valeur = %08f\n", (void *)f, *f);
	printf("d_value   : adresse = %p, valeur = %08f\n", (void *)d, *d);
	printf("ld_value  : adresse = %p, valeur = %08Lf\n", (void *)ld, *ld);

    //Exemple : modifier la valeur d'une variable via son pointeur

    *c = 'G';
    *s = 16;

    printf("\nAprès modification via les pointeurs :\n");
	printf("c_value   : adresse = %p, valeur = %08X\n", (void *)c, *c);
    printf("s_value   : adresse = %p, valeur = %08X\n", (void *)s, *s);
    
	return 0;
}

