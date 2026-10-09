#ifndef LISTE_H
#define LISTE_H

/* Une couleur : rouge, vert, bleu, alpha (chaque composante de 0x00 à 0xFF) */
struct couleur {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

/* Un maillon de la liste : une couleur + l'adresse du maillon suivant */
struct element {
	struct couleur couleur;
	struct element *suivant;
};

/* La liste : on garde juste l'adresse du premier maillon */
struct liste_couleurs {
	struct element *tete;
};

void init_liste(struct liste_couleurs *liste);
void insertion(struct couleur *c, struct liste_couleurs *liste);
void parcours(struct liste_couleurs *liste);
void liberer_liste(struct liste_couleurs *liste);

#endif