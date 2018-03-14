#ifndef MARATHON_H
#define MARATHON_H
#include "main.h"
#include "images.h"
#include "pause.h"
#include "score.h"
#include "son.h"
#include "options.h"
#include "jeu.h"
/*marathon.h: fichier inclut dans fmain.h, contient les définitions de toutes les fonctions nécessaires à une partie*/

//fonctions de partie marathon
void partieMarathon(ALLEGRO_DISPLAY *fenetre, int niveauChoisi, gameConfig *config, packSons *sons); //lance une partie de TETRIS au niveau sélectionné
void afficherPartieMarathon(packPartie *images, elementsFondPartie *elem, gameData *data); //va afficher la partie

#endif
