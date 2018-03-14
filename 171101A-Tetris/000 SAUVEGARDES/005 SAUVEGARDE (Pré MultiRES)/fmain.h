#ifndef FMAIN_H
#define FMAIN_H
#include "main.h"
#include "images.h"
#include "marathon.h"
#include "sprint.h"
#include "ultra.h"
#include "aide.h"
#include "son.h"
#include "options.h"
#include "data_files.h"
/*fmain.h: fichier qu'on inclut dans le main, dans lequel on va stocker les prototypes de "fmain.c" */

ALLEGRO_DISPLAY *genererFenetre(); //on génère et on affiche la fenêtre principale
void menuPrincipal(); //on entre dans le menu principal
int estSurUnBouton(elementsFondMenu *elem, int x, int y, int modeDeJeu); //vérifie si la souris est sur un bouton
void afficherMenuPrincipal(packMenu *images, elementsFondMenu *elem, int boutonOn, int niveau, int modeDeJeu); //va afficher le menu principal
void libererMemoire(ALLEGRO_DISPLAY *fenetre); //on libère la mémoire
void cheatInputVerif(gameConfig *config, File *cheatStr); //si le jouer écrit CHEAT dans le menu, on active les fonctions de cheat

#endif
