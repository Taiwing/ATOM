#ifndef IMAGES_H
#define IMAGES_H
#include "main.h"
/*images.h: fichier qu'on va inclure dans les fichiers où on aura besoin de générer et de manipuler des images*/

//structure de coordonnées et de taille des éléments graphiques du jeu
typedef struct coord coord;
struct coord
{
  int x; //coordonnée x du point d'origine
  int y; //coordonnée y du point d'origine
  int x2; //coordonnée x du point de fin
  int y2; //coordonnée y du point de fin
  int w; //largeur
  int h; //hauteur
  int t; //épaisseur des traits
};

//structure où on placera les "coord" correspondant à chaque élément du menu
typedef struct elementsFondMenu elementsFondMenu; //11
struct elementsFondMenu
{
  coord *rectPrincipal;
  coord *rectJouer;
  coord *rectNiveau;
  coord *rectMode;
  coord *rectScores;
  coord *rectAide;
  coord *rectOptions;
  coord *rectPieceSuiv;
  coord *rectNSL;

  coord *rectMenuAide;
  coord *rectOk;
};

//structure d'images pour le menu principal
typedef struct packMenu packMenu;
struct packMenu
{
  ALLEGRO_BITMAP *fondMenu;
  ALLEGRO_BITMAP *highScore;
  ALLEGRO_BITMAP *highTemps;
  ALLEGRO_BITMAP *highLines;
  ALLEGRO_BITMAP *boutonJouerOff;
  ALLEGRO_BITMAP *boutonJouerOn;
  ALLEGRO_BITMAP *boutonMarathonOff;
  ALLEGRO_BITMAP *boutonMarathonOn;
  ALLEGRO_BITMAP *boutonSprintOff;
  ALLEGRO_BITMAP *boutonSprintOn;
  ALLEGRO_BITMAP *boutonUltraOff;
  ALLEGRO_BITMAP *boutonUltraOn;
  ALLEGRO_BITMAP *boutonAideOff;
  ALLEGRO_BITMAP *boutonAideOn;
  ALLEGRO_BITMAP *boutonOptionsOff;
  ALLEGRO_BITMAP *boutonOptionsOn;
  ALLEGRO_BITMAP *boutonNiveau1Off;
  ALLEGRO_BITMAP *boutonNiveau2Off;
  ALLEGRO_BITMAP *boutonNiveau3Off;
  ALLEGRO_BITMAP *boutonNiveau4Off;
  ALLEGRO_BITMAP *boutonNiveau5Off;
  ALLEGRO_BITMAP *boutonNiveau6Off;
  ALLEGRO_BITMAP *boutonNiveau7Off;
  ALLEGRO_BITMAP *boutonNiveau8Off;
  ALLEGRO_BITMAP *boutonNiveau9Off;
  ALLEGRO_BITMAP *boutonNiveau10Off;
  ALLEGRO_BITMAP *boutonNiveau11Off;
  ALLEGRO_BITMAP *boutonNiveau12Off;
  ALLEGRO_BITMAP *boutonNiveau13Off;
  ALLEGRO_BITMAP *boutonNiveau14Off;
  ALLEGRO_BITMAP *boutonNiveau15Off;
  ALLEGRO_BITMAP *boutonNiveau16Off;
  ALLEGRO_BITMAP *boutonNiveau17Off;
  ALLEGRO_BITMAP *boutonNiveau18Off;
  ALLEGRO_BITMAP *boutonNiveau19Off;
  ALLEGRO_BITMAP *boutonNiveau20Off;
  ALLEGRO_BITMAP *boutonNiveau21Off;
  ALLEGRO_BITMAP *boutonNiveau22Off;
  ALLEGRO_BITMAP *boutonNiveau23Off;
  ALLEGRO_BITMAP *boutonNiveau24Off;
  ALLEGRO_BITMAP *boutonNiveau25Off;
  ALLEGRO_BITMAP *boutonNiveau26Off;
  ALLEGRO_BITMAP *boutonNiveau27Off;
  ALLEGRO_BITMAP *boutonNiveau28Off;
  ALLEGRO_BITMAP *boutonNiveau29Off;
  ALLEGRO_BITMAP *boutonNiveau30Off;
  ALLEGRO_BITMAP *boutonNiveau1On;
  ALLEGRO_BITMAP *boutonNiveau2On;
  ALLEGRO_BITMAP *boutonNiveau3On;
  ALLEGRO_BITMAP *boutonNiveau4On;
  ALLEGRO_BITMAP *boutonNiveau5On;
  ALLEGRO_BITMAP *boutonNiveau6On;
  ALLEGRO_BITMAP *boutonNiveau7On;
  ALLEGRO_BITMAP *boutonNiveau8On;
  ALLEGRO_BITMAP *boutonNiveau9On;
  ALLEGRO_BITMAP *boutonNiveau10On;
  ALLEGRO_BITMAP *boutonNiveau11On;
  ALLEGRO_BITMAP *boutonNiveau12On;
  ALLEGRO_BITMAP *boutonNiveau13On;
  ALLEGRO_BITMAP *boutonNiveau14On;
  ALLEGRO_BITMAP *boutonNiveau15On;
  ALLEGRO_BITMAP *boutonNiveau16On;
  ALLEGRO_BITMAP *boutonNiveau17On;
  ALLEGRO_BITMAP *boutonNiveau18On;
  ALLEGRO_BITMAP *boutonNiveau19On;
  ALLEGRO_BITMAP *boutonNiveau20On;
  ALLEGRO_BITMAP *boutonNiveau21On;
  ALLEGRO_BITMAP *boutonNiveau22On;
  ALLEGRO_BITMAP *boutonNiveau23On;
  ALLEGRO_BITMAP *boutonNiveau24On;
  ALLEGRO_BITMAP *boutonNiveau25On;
  ALLEGRO_BITMAP *boutonNiveau26On;
  ALLEGRO_BITMAP *boutonNiveau27On;
  ALLEGRO_BITMAP *boutonNiveau28On;
  ALLEGRO_BITMAP *boutonNiveau29On;
  ALLEGRO_BITMAP *boutonNiveau30On;

  ALLEGRO_BITMAP *fondMenuAide;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images du menu principal
packMenu *genererPackMenu(elementsFondMenu *elem); //on génère la structure d'images
void destroyPackMenu(packMenu *images); //on détruit la structure d'image
ALLEGRO_BITMAP *genererFondMenu(elementsFondMenu *elem); //va générer l'image de fond du menu principal
ALLEGRO_BITMAP *genererHigh(int modeDeJeu, elementsFondMenu *elem); //va générer le panneau de score, de temps et de lignes
elementsFondMenu *genererElementsFondMenu(); //va générer les "coord" de chaque élément du menu
void destroyElementsFondMenu(elementsFondMenu *elem); //on détruit la structure de "coord"
ALLEGRO_BITMAP *genererBoutonMenu(int typeDeBouton, int onOff, int niveau, elementsFondMenu *elem); //va générer les boutons du menu

//structure où on placera les "coord" correspondant à chaque élément de la partie
typedef struct elementsFondPartie elementsFondPartie; //11
struct elementsFondPartie
{
  coord *rectPrincipal;
  coord *rectPieceSuiv;
  coord *rectNSL;
  coord *rectTemps;

  coord *rectPause;
  coord *rectReprendre;
  coord *rectAide;
  coord *rectOptions;
  coord *rectQuitter;

  coord *rectMenuAide;
  coord *rectOk;
};

//structure d'images pour le ghost
typedef struct packGhost packGhost;
struct packGhost
{
  ALLEGRO_BITMAP *jauneo;
  ALLEGRO_BITMAP *cyaniPOS1;
  ALLEGRO_BITMAP *cyaniPOS2;
  ALLEGRO_BITMAP *cyaniPOS3;
  ALLEGRO_BITMAP *cyaniPOS4;
  ALLEGRO_BITMAP *rougezPOS1;
  ALLEGRO_BITMAP *rougezPOS2;
  ALLEGRO_BITMAP *rougezPOS3;
  ALLEGRO_BITMAP *rougezPOS4;
  ALLEGRO_BITMAP *vertsPOS1;
  ALLEGRO_BITMAP *vertsPOS2;
  ALLEGRO_BITMAP *vertsPOS3;
  ALLEGRO_BITMAP *vertsPOS4;
  ALLEGRO_BITMAP *mauvetPOS1;
  ALLEGRO_BITMAP *mauvetPOS2;
  ALLEGRO_BITMAP *mauvetPOS3;
  ALLEGRO_BITMAP *mauvetPOS4;
  ALLEGRO_BITMAP *orangelPOS1;
  ALLEGRO_BITMAP *orangelPOS2;
  ALLEGRO_BITMAP *orangelPOS3;
  ALLEGRO_BITMAP *orangelPOS4;
  ALLEGRO_BITMAP *violetjPOS1;
  ALLEGRO_BITMAP *violetjPOS2;
  ALLEGRO_BITMAP *violetjPOS3;
  ALLEGRO_BITMAP *violetjPOS4;
};

//structure d'images pour le menu de pause
typedef struct packPause packPause;
struct packPause
{
  ALLEGRO_BITMAP *fondPause;
  ALLEGRO_BITMAP *boutonReprendreOff;
  ALLEGRO_BITMAP *boutonReprendreOn;
  ALLEGRO_BITMAP *boutonAideOff;
  ALLEGRO_BITMAP *boutonAideOn;
  ALLEGRO_BITMAP *boutonOptionsOff;
  ALLEGRO_BITMAP *boutonOptionsOn;
  ALLEGRO_BITMAP *boutonQuitterOff;
  ALLEGRO_BITMAP *boutonQuitterOn;

  ALLEGRO_BITMAP *fondMenuAide;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//structure d'images pour la partie
typedef struct packPartie packPartie;
struct packPartie
{
  ALLEGRO_BITMAP *fondPartie;
  ALLEGRO_BITMAP *blocJaune;
  ALLEGRO_BITMAP *blocCyan;
  ALLEGRO_BITMAP *blocMauve;
  ALLEGRO_BITMAP *blocViolet;
  ALLEGRO_BITMAP *blocOrange;
  ALLEGRO_BITMAP *blocVert;
  ALLEGRO_BITMAP *blocRouge;
  ALLEGRO_BITMAP *blocBlanc;
  ALLEGRO_BITMAP *barreGrilleVerticale;
  ALLEGRO_BITMAP *barreGrilleHorizontale;

  packPause *imagesPause;

  packGhost *ghostPiece;
};

//fonctions d'images de la partie
elementsFondPartie *genererElementsFondPartie(); //va générer les "coord" de chaque élément de la partie
void destroyElementsFondPartie(elementsFondPartie *elem); //on détruit la structure de "coord"
packPartie *genererPackPartie(elementsFondPartie *elem, int modeDeJeu); //on génère la structure d'images
void destroyPackPartie(packPartie *images); //on détruit la structure d'image
ALLEGRO_BITMAP *genererFondPartie(elementsFondPartie *elem, int modeDeJeu); //va générer l'image de fond de la partie
ALLEGRO_BITMAP *genererFondPause(elementsFondPartie *elem, ALLEGRO_BITMAP *fondPartie); //va générer l'image de fond du menu pause
ALLEGRO_BITMAP *genererBoutonPause(int typeDeBouton, int onOff, elementsFondPartie *elem); //va générer l'image des boutons du menu pause
ALLEGRO_BITMAP *genererBloc(int typeDeBloc); //va générer les blocs du jeu
ALLEGRO_BITMAP *genererGhostPiece(int typeDeBloc, int position, packPartie *images); //va générer les images pour la fonction ghost

//fonctions d'image de l'écran d'aide
ALLEGRO_BITMAP *genererBoutonOk(int onOff, coord *rectOk); //va générer les deux images du bouton OK
//va générer l'image de fond du menu aide
ALLEGRO_BITMAP *genererFondMenuAide(elementsFondMenu *elemMenu, elementsFondPartie *elemPartie);

//structure d'éléments de scoreInput
typedef struct elementsFondScoreInput elementsFondScoreInput; //3
struct elementsFondScoreInput
{
  coord *rectPrincipal;
  coord *rectInput;
  coord *rectOk;
};

//structure d'image de scoreInput
typedef struct packScoreInput packScoreInput;
struct packScoreInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de scoreInput
elementsFondScoreInput *genererElementsFondScoreInput(); //va générer les "coord" de chaque élément de scoreInput
void destroyElementsFondScoreInput(elementsFondScoreInput *elem); //va détruire la structure de "coord"
packScoreInput *genererPackScoreInput(ALLEGRO_BITMAP *fondPrecedent, elementsFondScoreInput *elem, int score); //va générer le pack d'images de scoreInput
void destroyPackScoreInput(packScoreInput *images); //va détruire la structure d'images de scoreInput
ALLEGRO_BITMAP *genererFondScoreInput(ALLEGRO_BITMAP *fondPrecedent, elementsFondScoreInput *elem, int score); //va générer le fond de scoreInput

//structure où on placera les "coord" correspondant à chaque élément du menu d'options
typedef struct elementsFondOptions elementsFondOptions; //21
struct elementsFondOptions
{
  coord *rectPrincipal;
  coord *rectOk;
  coord *rectIrotater;
  coord *rectIsoftd;
  coord *rectIleft;
  coord *rectIright;
  coord *rectIhardd;
  coord *rectIrotatel;
  coord *rectIpause;
  coord *rectIghost;
  coord *rectIchange;
  coord *rectVolThemeM;
  coord *rectVolThemeP;
  coord *rectVolFXM;
  coord *rectVolFXP;
  coord *rectReset;

  coord *rectInputOptions;
  coord *rectTouche1;
  coord *rectTouche2;
  coord *rectTouche3;
  coord *rectOkInpOpt;
};

//structure d'images pour le menu d'options
typedef struct packOptions packOptions;
struct packOptions
{
  ALLEGRO_BITMAP *fondOptions;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
  ALLEGRO_BITMAP *inputrotaterOff;
  ALLEGRO_BITMAP *inputrotaterOn;
  ALLEGRO_BITMAP *inputsoftdOff;
  ALLEGRO_BITMAP *inputsoftdOn;
  ALLEGRO_BITMAP *inputleftOff;
  ALLEGRO_BITMAP *inputleftOn;
  ALLEGRO_BITMAP *inputrightOff;
  ALLEGRO_BITMAP *inputrightOn;
  ALLEGRO_BITMAP *inputharddOff;
  ALLEGRO_BITMAP *inputharddOn;
  ALLEGRO_BITMAP *inputrotatelOff;
  ALLEGRO_BITMAP *inputrotatelOn;
  ALLEGRO_BITMAP *inputpauseOff;
  ALLEGRO_BITMAP *inputpauseOn;
  ALLEGRO_BITMAP *inputghostOff;
  ALLEGRO_BITMAP *inputghostOn;
  ALLEGRO_BITMAP *inputchangeOff;
  ALLEGRO_BITMAP *inputchangeOn;
  ALLEGRO_BITMAP *boutonVolThemeMOff;
  ALLEGRO_BITMAP *boutonVolThemeMOn;
  ALLEGRO_BITMAP *boutonVolThemePOff;
  ALLEGRO_BITMAP *boutonVolThemePOn;
  ALLEGRO_BITMAP *boutonVolFXMOff;
  ALLEGRO_BITMAP *boutonVolFXMOn;
  ALLEGRO_BITMAP *boutonVolFXPOff;
  ALLEGRO_BITMAP *boutonVolFXPOn;
  ALLEGRO_BITMAP *boutonResetOff;
  ALLEGRO_BITMAP *boutonResetOn;

  ALLEGRO_BITMAP *fondInputOptions;
  ALLEGRO_BITMAP *boutonOkInpOptOff;
  ALLEGRO_BITMAP *boutonOkInpOptOn;
  ALLEGRO_BITMAP *touche1Off;
  ALLEGRO_BITMAP *touche1On;
  ALLEGRO_BITMAP *touche2Off;
  ALLEGRO_BITMAP *touche2On;
  ALLEGRO_BITMAP *touche3Off;
  ALLEGRO_BITMAP *touche3On;
};

//fonctions d'images du menu d'options
packOptions *genererPackOptions(elementsFondOptions *elem, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3]); //on génère la structure d'images
void destroyPackOptions(packOptions *images); //on détruit la structure d'image
//va générer l'image de fond du menu d'options
ALLEGRO_BITMAP *genererFondOptions(elementsFondOptions *elem, ALLEGRO_BITMAP *fondPrecedent, int recharge);
elementsFondOptions *genererElementsFondOptions(); //va générer les "coord" de chaque élément du menu options
void destroyElementsFondOptions(elementsFondOptions *elem); //on détruit la structure de "coord"
//va générer les boutons du menu d'options
ALLEGRO_BITMAP *genererBoutonOptions(int typeDeBouton, int onOff, elementsFondOptions *elem, int keyMap[16][3]);
void strTouche(int typeDeBouton, int keyMap[16][3], char str[40]); //va renvoyer un string contenant le nom de la touche correspondant au bouton entré
ALLEGRO_BITMAP *genererFondInputOptions(elementsFondOptions *elem, ALLEGRO_BITMAP *fondPrecedent); //va générer l'image d'inputOptions
ALLEGRO_BITMAP *genererBoutonInputOptions(int typeDeBouton, int onOff, elementsFondOptions *elem); //va générer les boutons de l'input

//structure d'éléments de tempsInput
typedef struct elementsFondTempsInput elementsFondTempsInput; //3
struct elementsFondTempsInput
{
  coord *rectPrincipal;
  coord *rectInput;
  coord *rectOk;
};

//structure d'image de tempsInput
typedef struct packTempsInput packTempsInput;
struct packTempsInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de tempsInput
elementsFondTempsInput *genererElementsFondTempsInput(); //va générer les "coord" de chaque élément de tempsInput
void destroyElementsFondTempsInput(elementsFondTempsInput *elem); //va détruire la structure de "coord"
packTempsInput *genererPackTempsInput(ALLEGRO_BITMAP *fondPrecedent, elementsFondTempsInput *elem, int temps); //va générer le pack d'images de tempsInput
void destroyPackTempsInput(packTempsInput *images); //va détruire la structure d'images de tempsInput
ALLEGRO_BITMAP *genererFondTempsInput(ALLEGRO_BITMAP *fondPrecedent, elementsFondTempsInput *elem, int temps); //va générer le fond de tempsInput

//structure d'éléments de lignesInput
typedef struct elementsFondLignesInput elementsFondLignesInput; //3
struct elementsFondLignesInput
{
  coord *rectPrincipal;
  coord *rectInput;
  coord *rectOk;
};

//structure d'image de lignesInput
typedef struct packLignesInput packLignesInput;
struct packLignesInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de lignesInput
elementsFondLignesInput *genererElementsFondLignesInput(); //va générer les "coord" de chaque élément de lignesInput
void destroyElementsFondLignesInput(elementsFondLignesInput *elem); //va détruire la structure de "coord"
packLignesInput *genererPackLignesInput(ALLEGRO_BITMAP *fondPrecedent, elementsFondLignesInput *elem, int lignes); //va générer le pack d'images de lignesInput
void destroyPackLignesInput(packLignesInput *images); //va détruire la structure d'images de lignesInput
ALLEGRO_BITMAP *genererFondLignesInput(ALLEGRO_BITMAP *fondPrecedent, elementsFondLignesInput *elem, int lignes); //va générer le fond de lignesInput

#endif
