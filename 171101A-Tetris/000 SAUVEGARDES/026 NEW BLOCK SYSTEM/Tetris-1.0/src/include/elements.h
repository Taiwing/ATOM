#ifndef ELEMENTS_S
#define ELEMENTS_S
#include "main.h"

//structure de coordonnées et de taille des éléments graphiques du jeu
typedef struct coord coord;
struct coord
{
  //valeurs coord par défaut
  int defx; //coordonnée x du point d'origine
  int defy; //coordonnée y du point d'origine
  int defx2; //coordonnée x du point de fin
  int defy2; //coordonnée y du point de fin
  int defw; //largeur
  int defh; //hauteur
  int deft; //épaisseur des traits

  //valeurs coord modofiées en fonction de la résolution et utilisées par les fonctions de dessin
  float x; //coordonnée x du point d'origine
  float y; //coordonnée y du point d'origine
  float x2; //coordonnée x du point de fin
  float y2; //coordonnée y du point de fin
  float w; //largeur
  float h; //hauteur
  float t; //épaisseur des traits
};

//structure où on placera les "coord" correspondant à chaque élément du jeu
typedef struct elements elements; //42
struct elements
{
  //éléments globaux
  coord *rectPrincipal; //cadre principal du jeu
  coord *rectScores; //cadre où on va afficher le panneau de scores/temps/lignes
  coord *rectPieceSuiv; //cadre où on va afficher la prochaine pièce
  coord *rectNSL; //cadre où on va afficher le niveau, le score et le nombre de lignes
  coord *rectTemps; //cadre juste en dessous de NSL qui sert à afficher le timer dans partieSprint et partieUltra
  coord *rectAide; //cadre du panneau d'aide
  coord *rectPause; //cadre du menu pause
  coord *rectOptions; //cadre du menu options
  coord *rectInputOptions; //cadre de l'input des touches dans le menu options
  coord *rectSTLInput; //cadre de l'image des fonctions scoreInput lignesInput et tempsInput

  //éléments boutons
  //Menu Principal
  coord *rectBMenuJouer;
  coord *rectBMenuNiveau;
  coord *rectBMenuMode;
  coord *rectBMenuAide;
  coord *rectBMenuOptions;
  //Aide
  coord *rectBAideOk;
  //Pause
  coord *rectBPauseReprendre;
  coord *rectBPauseAide;
  coord *rectBPauseOptions;
  coord *rectBPauseQuitter;
  //Options
  coord *rectBOptionsVolThemeM;
  coord *rectBOptionsVolThemeP;
  coord *rectBOptionsVolFXM;
  coord *rectBOptionsVolFXP;
  coord *rectBOptionsReset;
  coord *rectBOptionsOk;
  //Input Options
  coord *rectBInputOptionsOk;
  //STL input (fonctions d'input des fonctions high (ScoreTempsLignes))
  coord *rectBSTLOk;

  //éléments input
  //Options
  coord *rectIOptionsLeft;
  coord *rectIOptionsRight;
  coord *rectIOptionsRotatel;
  coord *rectIOptionsRotater;
  coord *rectIOptionsHardd;
  coord *rectIOptionsSoftd;
  coord *rectIOptionsPause;
  coord *rectIOptionsGhost;
  coord *rectIOptionsChange;
  //Input Options
  coord *rectIInputOptionsTouche1;
  coord *rectIInputOptionsTouche2;
  coord *rectIInputOptionsTouche3;
  //STL input
  coord *rectISTLInput;
};

//fonctions de la structure d'éléments
elements *genererElements(); //va générer le pack d'éléments de base (on va utiliser "free" pour la détruire)
void resizeElements(elements *elem, float scale); //va redimensionner les éléments du jeu en fonction de la résolution (du facteur scale pour le moment)

#endif
