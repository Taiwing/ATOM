#ifndef JEU_H
#define JEU_H
#include "main.h"
#include "images.h"
#include "pause.h"
#include "score.h"
#include "son.h"
/*jeu.h: fichier inclut dans fmain.h, contient les définitions de toutes les fonctions nécessaires à une partie*/

void partie(ALLEGRO_DISPLAY *fenetre, int niveau, bool sound[3], packSons *sons); //lance une partie de TETRIS au niveau sélectionné
void afficherPartie(packPartie *images,
                    elementsFondPartie *elem,
                    packTetro *tetros,
                    int grille[GRID_W][GRID_H],
                    int tetroSuivant[4][5],
                    bool animDisp,
                    int niveau, int score, int lignes); //va afficher la partie
void selectionAleatoireTetromino(int tetroActuel[4][5], packTetro *tetros, int sac[7], int nbTetro); //va sélectionner le prochain tétromino
void randomGenerator(int sac[7]); //va sélectionner aléatoirement les 7 prochains tétrosminos
bool placerTetro(int grille[GRID_W][GRID_H],
                 int tetroSuivant[4][5],
                 int tetroActuel[4][5]); //on met le tetroSuivant dans tetroActuel, et on le place dans la grille
//va déplacer la pièce si le mouvement est légal (et renvoyer "nextTetro = true" s'il faut changer de pièce)
int deplacerTetro(int mouvement, int grille[GRID_W][GRID_H], int tetroActuel[4][5], packTetro *tetros, int *niveau, int *score);
//test le déplacement dans "deplacerPiece" et renvoit 0, 1 ou 2 (0: interdit, 1: légal, 2: illégal et pièce suivante)
int testDeplacement(int mouvement, int grille[GRID_W][GRID_H], int tetroActuel[4][5], packTetro *tetros);
//va tester si le tétro est sur le point de se bloquer
bool lockTest(int grille[GRID_W][GRID_H], int tetroActuel[4][5]);
//va bloquer le tétromino dans la grille
void lockTetro(int grile[GRID_W][GRID_H], int tetroActuel[4][5]);
//va vérifier s'il y a une ou plusieurs lignes complétées
bool ligneComplete(int grille[GRID_W][GRID_H], File *soundEv);
//va enlever les lignes complètes, et faire descendre celles du dessus s'il y en a
int enleverLignes(int grille[GRID_W][GRID_H]);
void scoring(int *score, int niveau, int action, int *dernierCoup, int *comboCount); //va calculer le score
void leveling(int *niveau, int *score, int *vitesse, File *soundEv); //se charge du changement de niveau et détermine la vitesse en fonction
void ghostPiece(packPartie *images, int grille[GRID_W][GRID_H], int tetroActuel[4][5]); //va afficher le tétro fantôme
bool holdPiece(int tetroActuel[4][5], int tetroSuivant[4][5], int grille[GRID_W][GRID_H]); //va retenir le tétro actuel
 //va déclencher un compte à rebours de trois secondes
void troisDeuxUn(packPartie *images, elementsFondPartie *elem, int pause, int niveau, int score, int lignes);
bool TSpinTest(int grille[GRID_W][GRID_H], int tetroActuel[4][5]); //va dire s'il y a T-Spin ou non
bool testTouchLR(int grille[GRID_W][GRID_H], int tetroActuel[4][5]); //va indiquer si le tétromino actuel touche un bloc ou un mur

#endif
