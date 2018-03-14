#ifndef FMAIN_H
#define FMAIN_H
#include "main.h"
#include "fenetre.h"
#include "marathon.h"
#include "sprint.h"
#include "ultra.h"
#include "aide.h"
#include "son.h"
#include "options.h"
#include "data_files.h"
/*fmain.h: fichier qu'on inclut dans le main, dans lequel on va stocker les prototypes de "fmain.c" */

void menuPrincipal(); //on entre dans le menu principal
void chargerListeElemFondMenu(gameScreen *screen, elementsFondMenu *elem, Liste *lElem); //va charger la liste pour la fonction "estSurUnBouton"
int estSurUnBouton(Liste *lElem, int x, int y, int modeDeJeu); //vérifie si la souris est sur un bouton
void afficherMenuPrincipal(gameScreen *screen, packMenu *images, elementsFondMenu *elem, int boutonOn, int niveau, int modeDeJeu); //va afficher le menu principal
void cheatInputVerif(gameConfig *config, File *cheatStr); //si le jouer écrit CHEAT dans le menu, on active les fonctions de cheat

#endif
