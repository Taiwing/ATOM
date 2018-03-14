#ifndef FENETRE_H
#define FENETRE_H
#include "images.h"
#include "data_list.h"

//structure de l'écran du jeu
typedef struct gameScreen gameScreen;
struct gameScreen
{
  ALLEGRO_DISPLAY *display; //fenêtre du jeu
  ALLEGRO_BITMAP *buffer; //image affichée sur laquelle on va dessiner toutes les autres (est à la résolution du jeu mais a des proportions fixes)
  ALLEGRO_BITMAP *fondDuJeu; //image de fond (fait toujours la taille de la fenêtre, et est à la même résolution que le jeu)
  float sx; //facteur d'échelle x
  float sy; //facteur d'échelle y
  float scale; //va stocker le plus petit des facteurs d'échelle
  float scaleW;
  float scaleH;
  float scaleX;
  float scaleY;
  float fondW; //va déterminer la largeur du fond du jeu
  float fondH; //va déterminer la hauteur du fond du jeu
  bool fullScreenSwitch;

  //va stocker les contôles de la fenêtre (plein écran)
  int windowKeys[2];
};

//fonction de l'écran de jeu
gameScreen *genererGameScreen(); //on génère et on affiche la fenêtre principale
void destroyGameScreen(gameScreen *screen); //on libère la mémoire
void resizeGameScreen(gameScreen *screen); //va changer la taille de l'écran du jeu
void fullScreen(gameScreen *screen); //va activer ou désactiver le mode plein écran
void targetBuffer(gameScreen *screen); //va cibler le buffer et dessiner le fondDuJeu dessus
void drawBuffer(gameScreen *screen); //va dessiner le buffer à l'écran

//fonction de redéfinition des coordonnées des boutons du jeu
void elemToList(gameScreen *screen, Liste *lElem, coord *rect); //va ajouter chaque coord à une liste de coord en le mettant à l'échelle
int posMouse(Liste *lElem, int x, int y); //va renvoyer la position du rect de la liste si la souris se trouve dessus (0 par défaut)

//fonctions d'input de la fenêtre
void windowInputKeyDown(gameScreen *screen, int key, bool *legalInput);
void windowInputKeyUp(gameScreen *screen, int key, bool *legalInput);

#endif
