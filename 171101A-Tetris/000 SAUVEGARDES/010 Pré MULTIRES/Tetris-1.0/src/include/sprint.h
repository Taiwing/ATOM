#ifndef SPRINT_H
#define SPRINT_H
#include "main.h"
#include "fenetre.h"
#include "pause.h"
#include "time.h"
#include "son.h"
#include "options.h"
#include "jeu.h"
/*sprint.h: fichier inclut dans fmain.h, contient les définitions de toutes les fonctions nécessaires à une partie*/

//fonctions de jeu
void partieSprint(gameScreen *screen, int niveauChoisi, gameConfig *config, packSons *sons); //lance une partie de TETRIS au niveau sélectionné
void afficherPartieSprint(gameScreen *screen, packPartie *images, elementsFondPartie *elem, gameData *data, int timerSprint); //va afficher la partie

#endif
