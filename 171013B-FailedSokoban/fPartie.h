#ifndef FPARTIE_H
#define FPARTIE_H
#include "main.h"

void phdMario(SDL_Rect* hitboxMario, int niveau[144]);
void genererNiveauHitbox(int niveau[144], SDL_Rect niveauHitbox[144]);
void deplacerHitbox(SDL_Rect* hitbox, char direction, int vitesse);
int testMouvement(SDL_Rect hitboxMario, int niveau[144], SDL_Rect niveauHitbox[144], char direction, int vitesse, SDL_Window* sokoban, int* decalage);
int testMouvementCaisse(SDL_Rect hitboxCaisse, int niveau[144], SDL_Rect niveauHitbox[144], int positionCaisse, char direction, SDL_Window* sokoban, int* coordCroisementTMC, int* decalage, int vitesse);
void afficherMouvement(SDL_Rect hitbox, char direction, int vitesse, SDL_Window* sokoban, int niveau[144]);
void reafficherObjectif(SDL_Rect positionPrecedente, SDL_Surface* surface, int niveau[144]);
void afficherMouvementCaisse(SDL_Rect hitbox, char direction, int vitesse, SDL_Window* sokoban, int niveau[144]);
void valideCaisse(int coordCroisement, int niveau[144], SDL_Rect niveauHitbox[144], int positionCaisse, SDL_Window* sokoban);
void decaler(int* decalage, SDL_Rect* hitbox, char direction, SDL_Window* sokoban, int niveau[144]);
void decalerCaisse(int* decalage, SDL_Rect* hitboxCaisse, char direction, SDL_Window* sokoban, int niveau[144]);
void testVictoire(int* continuer, int niveau[144], SDL_Window* sokoban);

#endif
