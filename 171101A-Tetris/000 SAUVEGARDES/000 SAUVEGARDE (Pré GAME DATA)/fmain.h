#ifndef FMAIN_H
#define FMAIN_H
#include "main.h"
#include "images.h"
#include "jeu.h"
#include "aide.h"
#include "son.h"
/*fmain.h: fichier qu'on inclut dans le main, dans lequel on va stocker les prototypes de "fmain.c" */

ALLEGRO_DISPLAY *genererFenetre(); //on génère et on affiche la fenêtre principale
void menuPrincipal(); //on entre dans le menu principal
int estSurUnBouton(elementsFondMenu *elem, int x, int y); //vérifie si la souris est sur un bouton
void afficherMenuPrincipal(packMenu *images, elementsFondMenu *elem, int boutonOn, int niveau); //va afficher le menu principal
void libererMemoire(ALLEGRO_DISPLAY *fenetre); //on libère la mémoire

#endif
