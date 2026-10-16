/*

une fichier.h sert à déclarer les fonctions pour lire et écrire dans un fichier.*
par exemple, la fonction lire_fichier prend en paramètre le nom du fichier à lire et affiche son contenu à l'écran. La fonction ecrire_dans_fichier prend en paramètre le nom du fichier dans lequel écrire et le message à écrire dans ce fichier.
on a besoin de ce fichier.h pour pouvoir utiliser ces fonctions dans d'autres fichiers.c, comme main.c. En incluant fichier.h dans main.c, on peut appeler les fonctions lire_fichier et ecrire_dans_fichier sans avoir à les redéfinir dans main.c.


*/


#ifndef REPERTOIRE_H
#define REPERTOIRE_H

void lire_dossier(char *nom_du_repertoire); 
void lire_dossier_recursif(const char *nom_du_repertoire);
void lire_dossier_iteratif(const char *nom_du_repertoire);

#endif