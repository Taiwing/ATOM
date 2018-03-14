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
packMenu *genererPackMenu(elements *elem); //on génère la structure d'images
void destroyPackMenu(packMenu *images); //on détruit la structure d'image
ALLEGRO_BITMAP *genererFondMenu(elements *elem); //va générer l'image de fond du menu principal
ALLEGRO_BITMAP *genererHigh(int modeDeJeu, elements*elem); //va générer le panneau de score, de temps et de lignes
ALLEGRO_BITMAP *genererBoutonMenu(int typeDeBouton, int onOff, int niveau, elements *elem); //va générer les boutons du menu

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
packPartie *genererPackPartie(elements *elem, int modeDeJeu); //on génère la structure d'images
void destroyPackPartie(packPartie *images); //on détruit la structure d'image
ALLEGRO_BITMAP *genererFondPartie(elements *elem, int modeDeJeu); //va générer l'image de fond de la partie
ALLEGRO_BITMAP *genererFondPause(elements *elem, ALLEGRO_BITMAP *fondPartie); //va générer l'image de fond du menu pause
ALLEGRO_BITMAP *genererBoutonPause(int typeDeBouton, int onOff, elements *elem); //va générer l'image des boutons du menu pause
ALLEGRO_BITMAP *genererBloc(int typeDeBloc); //va générer les blocs du jeu
ALLEGRO_BITMAP *genererGhostPiece(int typeDeBloc, int position, packPartie *images); //va générer les images pour la fonction ghost

//fonctions d'image de l'écran d'aide
ALLEGRO_BITMAP *genererBoutonOk(int onOff, coord *rectOk); //va générer les deux images du bouton OK
//va générer l'image de fond du menu aide
ALLEGRO_BITMAP *genererFondMenuAide(elements *elem, bool menu);

//structure d'image de scoreInput
typedef struct packScoreInput packScoreInput;
struct packScoreInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de scoreInput
packScoreInput *genererPackScoreInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int score); //va générer le pack d'images de scoreInput
void destroyPackScoreInput(packScoreInput *images); //va détruire la structure d'images de scoreInput
ALLEGRO_BITMAP *genererFondScoreInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int score); //va générer le fond de scoreInput


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
packOptions *genererPackOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3]); //on génère la structure d'images
void destroyPackOptions(packOptions *images); //on détruit la structure d'image
//va générer l'image de fond du menu d'options
ALLEGRO_BITMAP *genererFondOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, int recharge);
//va générer les boutons du menu d'options
ALLEGRO_BITMAP *genererBoutonOptions(int typeDeBouton, int onOff, elements *elem, int keyMap[16][3]);
void strTouche(int typeDeBouton, int keyMap[16][3], char str[40]); //va renvoyer un string contenant le nom de la touche correspondant au bouton entré
ALLEGRO_BITMAP *genererFondInputOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent); //va générer l'image d'inputOptions
ALLEGRO_BITMAP *genererBoutonInputOptions(int typeDeBouton, int onOff, elements *elem); //va générer les boutons de l'input


//structure d'image de tempsInput
typedef struct packTempsInput packTempsInput;
struct packTempsInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de tempsInput
packTempsInput *genererPackTempsInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int temps); //va générer le pack d'images de tempsInput
void destroyPackTempsInput(packTempsInput *images); //va détruire la structure d'images de tempsInput
ALLEGRO_BITMAP *genererFondTempsInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int temps); //va générer le fond de tempsInput


//structure d'image de lignesInput
typedef struct packLignesInput packLignesInput;
struct packLignesInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de lignesInput
packLignesInput *genererPackLignesInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int lignes); //va générer le pack d'images de lignesInput
void destroyPackLignesInput(packLignesInput *images); //va détruire la structure d'images de lignesInput
ALLEGRO_BITMAP *genererFondLignesInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int lignes); //va générer le fond de lignesInput

//fonctions de dessin du buffer
void genererBande(ALLEGRO_BITMAP *bande); //va générer l'image pour remplir les bandes noires si la fenêtre est redimensionnée

#endif
