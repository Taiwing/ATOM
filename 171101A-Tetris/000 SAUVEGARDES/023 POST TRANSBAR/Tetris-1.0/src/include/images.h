#ifndef IMAGES_H
#define IMAGES_H
#include "main.h"
#include "elements.h"
/*images.h: fichier qu'on va inclure dans les fichiers où on aura besoin de générer et de manipuler des images*/

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
packMenu *genererPackMenu(elements *elem, float scale); //on génère la structure d'images
void destroyPackMenu(packMenu *images); //on détruit la structure d'image
ALLEGRO_BITMAP *genererFondMenu(elements *elem, float scale); //va générer l'image de fond du menu principal
ALLEGRO_BITMAP *genererHigh(int modeDeJeu, elements *elem, float scale); //va générer le panneau de score, de temps et de lignes
ALLEGRO_BITMAP *genererBoutonMenu(int typeDeBouton, int onOff, int niveau, elements *elem, float scale); //va générer les boutons du menu

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

  packPause *imagesPause;

  packGhost *ghostPiece;
};

//fonctions d'images de la partie
packPartie *genererPackPartie(elements *elem, int modeDeJeu, float scale); //on génère la structure d'images
void destroyPackPartie(packPartie *images); //on détruit la structure d'image
ALLEGRO_BITMAP *genererFondPartie(elements *elem, int modeDeJeu, float scale); //va générer l'image de fond de la partie
ALLEGRO_BITMAP *genererFondPause(elements *elem, ALLEGRO_BITMAP *fondPartie, float scale); //va générer l'image de fond du menu pause
ALLEGRO_BITMAP *genererBoutonPause(int typeDeBouton, int onOff, elements *elem, float scale); //va générer l'image des boutons du menu pause
ALLEGRO_BITMAP *genererGhostPiece(int typeDeBloc, int position, packPartie *images, float scale); //va générer les images pour la fonction ghost

//fonctions d'image de l'écran d'aide
ALLEGRO_BITMAP *genererBoutonOk(int onOff, coord *rectOk, float scale); //va générer les deux images du bouton OK
//va générer l'image de fond du menu aide
ALLEGRO_BITMAP *genererFondMenuAide(elements *elem, bool menu, float scale);

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
packOptions *genererPackOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3], float scale); //on génère la structure d'images
void destroyPackOptions(packOptions *images); //on détruit la structure d'image
//va générer l'image de fond du menu d'options
ALLEGRO_BITMAP *genererFondOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, int recharge, float scale);
//va générer les boutons du menu d'options
ALLEGRO_BITMAP *genererBoutonOptions(int typeDeBouton, int onOff, elements *elem, int keyMap[16][3], float scale);
void strTouche(int typeDeBouton, int keyMap[16][3], char str[40]); //va renvoyer un string contenant le nom de la touche correspondant au bouton entré
ALLEGRO_BITMAP *genererFondInputOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, float scale); //va générer l'image d'inputOptions
ALLEGRO_BITMAP *genererBoutonInputOptions(int typeDeBouton, int onOff, elements *elem, float scale); //va générer les boutons de l'input

//structure d'images de STLInput
typedef struct packSTLInput packSTLInput;
struct packSTLInput
{
  ALLEGRO_BITMAP *fond;
  ALLEGRO_BITMAP *boutonOkOff;
  ALLEGRO_BITMAP *boutonOkOn;
};

//fonctions d'images de STLInput
packSTLInput *genererPackSTLInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int score, int modeDeJeu, float scale); //va générer le pack d'images de STLInput
void destroyPackSTLInput(packSTLInput *images); //va détruire la structure d'images de scoreInput
ALLEGRO_BITMAP *genererFondSTLInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int score, int modeDeJeu, float scale); //va générer le fond de STLInput

//fonctions de dessin du buffer
void genererFondDujeu(ALLEGRO_BITMAP *fond); //va générer le fond du jeu
void drawBlock(int typeDeBloc, float posX, float posY, float scale); //va générer un block à la volée et le dessiner sur le buffer
void drawHorBarre(float posX, float posY, float scale); //va génénrer une barre horizontale à la volée et la dessiner sur le buffer
void drawVerBarre(float posX, float posY, float scale); //va génénrer une barre verticale à la volée et la dessiner sur le buffer
void drawTransHorBarre(float posX, float posY, float scale); //va génénrer une barre transparente horizontale à la volée et la dessiner sur le buffer
void drawTransVerBarre(float posX, float posY, float scale); //va génénrer une barre transparente verticale à la volée et la dessiner sur le buffer


//structure d'images globale
typedef struct packImages packImages;
struct packImages
{
  packMenu *imagesMenu;
  packPartie *imagesPartie;
  packOptions *imagesOptions;
  packSTLInput *imagesSTLInput;
};

//fonctions d'images
packImages *genererPackImages(elements *elem, int keyMap[16][3], float scale); //va générer les images du jeu à partir des coord d'elem
//va régénérer les images de la structure
void regenererPackImages(packImages *images, elements *elem, int regen, int modeDeJeu, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3], int score, float scale);
void destroyPackImages(packImages *images); //va détruire les images de la structure d'images globale (mais pas la structure)

#endif
