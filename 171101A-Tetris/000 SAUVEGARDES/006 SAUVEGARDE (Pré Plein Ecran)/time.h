#ifndef TIME_H
#define TIME_H
#include <string.h>
#include "main.h"
#include "fenetre.h"

//va recueillir les données de temps dans le fichier temps.tim
void lireFichierTemps(char J[5][4], char S[5][7]);

//va comparer le nouveau temps avec ceux du fichier et renvoyer sa place
//dans le podium s'il est supérieur à au moins l'un d'entre eux
int testTemps(int temps);

//va demander au joueur de rentrer son nom
void tempsInput(gameScreen *screen, char joueur[4], int temps);

//va rentrer le nouveau temps et le nom du joueur en fin de partie dans le tableau de temps s'il est dans le top 6
void nouveauTemps(char joueur[4], int temps, int place);

//fonction dans laquelle on va effectuer toutes les opérations de temps
void highTemps(gameScreen *screen, int temps);

//fonction de détection de la souris sur le bouton
int estSurUnBoutonTemps(Liste *lElem, int x, int y);

//fonction d'affichage de tempsInput
void afficherTempsInput(gameScreen *screen, packTempsInput *images, elementsFondTempsInput *elem, int boutonOk, char joueur[4]);

//fonction de chargement de la liste pour "estSurUnBouton"
void chargerListeElemFondTempsInput(gameScreen *screen, elementsFondTempsInput *elem, Liste *lElem);

#endif
