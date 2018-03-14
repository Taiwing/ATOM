#ifndef NIVEAUX_H
#define NIVEAUX_H
#include "main.h"

void choixNiveau(SDL_Window* sokoban, int niveau[144]); //menu de choix de niveau
void chargerNiveau(SDL_Window* sokoban, int niveau[144]); //on charge le niveau choisi dans la fenêtre de jeu

#endif
