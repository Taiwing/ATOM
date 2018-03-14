#ifndef LINES_H
#define LINES_H
#include <string.h>
#include "main.h"
#include "images.h"

//va recueillir les données de lignes dans le fichier lignes.lin
void lireFichierLignes(char J[5][4], char S[5][7]);

//va comparer le nouveau nombre de lignes avec ceux du fichier et renvoyer sa place
//dans le podium s'il est supérieur à au moins l'un d'entre eux
int testLignes(int lignes);

//va demander au joueur de rentrer son nom
void lignesInput(ALLEGRO_DISPLAY *fenetre, char joueur[4], int lignes);

//va rentrer le nouveau lignes et le nom du joueur en fin de partie dans le tableau de lignes s'il est dans le top 6
void nouveauLignes(char joueur[4], int lignes, int place);

//fonction dans laquelle on va effectuer toutes les opérations de lignes
void highLignes(ALLEGRO_DISPLAY *fenetre, int lignes);

//fonction de détection de la souris sur le bouton
int estSurUnBoutonLignes(coord *OK, int x, int y);

//fonction d'affichage de lignesInput
void afficherLignesInput(packLignesInput *images, elementsFondLignesInput *elem, int boutonOk, char joueur[4]);

#endif
