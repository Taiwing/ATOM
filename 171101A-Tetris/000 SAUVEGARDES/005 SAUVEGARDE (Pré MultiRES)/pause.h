#ifndef PAUSE_H
#define PAUSE_H
#include "main.h"
#include "images.h"
#include "aide.h"
#include "son.h"
#include "configuration.h"
#include "options.h"

//menu de pause de partie
bool menuPause(ALLEGRO_DISPLAY *fenetre, elementsFondPartie *elem, packPause *images, int niveau, int score, int lignes, packSons *sons, gameConfig *config);
int estSurUnBoutonPause(elementsFondPartie *elem, int x, int y); //va vérifier si la souris est sur un bouton du menu
void afficherPause(packPause *images, elementsFondPartie* elem, int bouton, int niveau, int score, int lignes); //va afficher le menu pause

#endif
