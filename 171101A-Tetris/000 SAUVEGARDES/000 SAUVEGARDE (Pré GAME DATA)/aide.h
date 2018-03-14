#ifndef AIDE_H
#define AIDE_H
#include "main.h"
#include "images.h"

void menuAide(ALLEGRO_DISPLAY *fenetre,
              ALLEGRO_BITMAP *fond, ALLEGRO_BITMAP *boutonOkON, ALLEGRO_BITMAP *boutonOkOFF,
              coord *Aide, coord *OK, coord *NSL,
              int niveau, int score, int lignes); //menu aide
int estSurUnBoutonAide(coord *OK, int x, int y); //va vérifier si la souris est sur un bouton du menu
void afficherAide(ALLEGRO_BITMAP *fond,
                  ALLEGRO_BITMAP *boutonOkON,
                  ALLEGRO_BITMAP *boutonOkOFF,
                  coord *OK,
                  coord *NSL,
                  int boutonOk,
                  int niveau, int score, int lignes); //va afficher l'aide

#endif
