#ifndef ULTRA_H
#define ULTRA_H
#include "main.h"
#include "images.h"
#include "pause.h"
#include "lines.h"
#include "son.h"
#include "options.h"
#include "jeu.h"
/*sprint.h: fichier inclut dans fmain.h, contient les définitions de toutes les fonctions nécessaires à une partie*/

//fonctions de jeu
void partieUltra(ALLEGRO_DISPLAY *fenetre, int niveauChoisi, gameConfig *config, packSons *sons); //lance une partie de TETRIS au niveau sélectionné
void afficherPartieUltra(packPartie *images, elementsFondPartie *elem, gameData *data, int timerUltra); //va afficher la partie

#endif
