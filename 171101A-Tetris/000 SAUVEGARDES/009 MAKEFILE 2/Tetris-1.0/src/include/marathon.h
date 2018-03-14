#ifndef MARATHON_H
#define MARATHON_H
#include "main.h"
#include "fenetre.h"
#include "pause.h"
#include "score.h"
#include "son.h"
#include "options.h"
#include "jeu.h"
/*marathon.h: fichier inclut dans fmain.h, contient les définitions de toutes les fonctions nécessaires à une partie*/

//fonctions de partie marathon
void partieMarathon(gameScreen *screen, int niveauChoisi, gameConfig *config, packSons *sons); //lance une partie de TETRIS au niveau sélectionné
void afficherPartieMarathon(gameScreen *screen, packPartie *images, elementsFondPartie *elem, gameData *data); //va afficher la partie

#endif
