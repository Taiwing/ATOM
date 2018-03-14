#ifndef AIDE_H
#define AIDE_H
#include "main.h"
#include "fenetre.h"

void menuAide(gameScreen *screen,
              ALLEGRO_BITMAP *fond, ALLEGRO_BITMAP *boutonOkON, ALLEGRO_BITMAP *boutonOkOFF,
              coord *Aide, coord *OK, coord *NSL,
              int niveau, int score, int lignes); //menu aide
int estSurUnBoutonAide(Liste *lElem, int x, int y); //va vérifier si la souris est sur un bouton du menu
void afficherAide(gameScreen *screen,
                  ALLEGRO_BITMAP *fond,
                  ALLEGRO_BITMAP *boutonOkON,
                  ALLEGRO_BITMAP *boutonOkOFF,
                  coord *OK,
                  coord *NSL,
                  int boutonOk,
                  int niveau, int score, int lignes); //va afficher l'aide
void chargerListeElemFondAide(gameScreen *screen, coord *OK, Liste *lElem); //va charger la liste des boutons accessibles à la souris

#endif
