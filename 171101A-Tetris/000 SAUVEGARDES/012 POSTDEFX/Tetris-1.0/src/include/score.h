#ifndef SCORE_H
#define SCORE_H
#include <string.h>
#include "main.h"
#include "fenetre.h"

//va recueillir les données de score dans le fichier highScore.sco
void lireFichierScore(char J[5][4], char S[5][7]);

//va comparer le nouveau score avec ceux du fichier de highScore et renvoyer sa place
//dans le high score s'il est supérieur à au moins l'un d'entre eux
int testScore(int score);

//va demander au joueur de rentrer son nom pour le high score
void scoreInput(gameScreen *screen, char joueur[4], int score, elements *elem);

//va rentrer le nouveau score et le nom du joueur en fin de partie dans le high score s'il est dans le top 6
void nouveauScore(char joueur[4], int score, int place);

//fonction dans laquelle on va effectuer toutes les opérations de score
void highScore(gameScreen *screen, int score, elements *elem);

//fonction de détection de la souris sur le bouton
int estSurUnBoutonScore(Liste *lElem, int x, int y);

//fonction d'affichage de scoreInput
void afficherScoreInput(gameScreen *screen, packScoreInput *images, elements *elem, int boutonOk, char joueur[4]);

//fonction de chargement de la liste pour "estSurUnBouton"
void chargerListeElemFondScoreInput(gameScreen *screen, elements *elem, Liste *lElem);

#endif
