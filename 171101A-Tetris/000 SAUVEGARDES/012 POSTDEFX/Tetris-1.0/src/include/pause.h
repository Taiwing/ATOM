#ifndef PAUSE_H
#define PAUSE_H
#include "main.h"
#include "fenetre.h"
#include "aide.h"
#include "son.h"
#include "configuration.h"
#include "options.h"

//menu de pause de partie
bool menuPause(gameScreen *screen, elements *elem, packPause *images, int niveau, int score, int lignes, packSons *sons, gameConfig *config);
int estSurUnBoutonPause(Liste *lElem, int x, int y); //va vérifier si la souris est sur un bouton du menu
void afficherPause(gameScreen *screen, packPause *images, elements* elem, int bouton, int niveau, int score, int lignes); //va afficher le menu pause
void chargerListeElemFondPause(gameScreen *screen, elements *elem, Liste *lElem); //va charger la liste pour la fonction "estSurUnBouton"

#endif
