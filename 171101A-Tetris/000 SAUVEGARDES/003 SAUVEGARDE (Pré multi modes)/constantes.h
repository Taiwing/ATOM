#ifndef CONST_H
#define CONST_H
/*constantes.h: fichier inclut dans main.h dans lequel on va stocker toutes les constantes du programme*/

#define FPS 60 //on met le jeu à 60 images par secondes
#define SCREEN_W 728 //largeur de la fenêtre
#define SCREEN_H 600 //hauteur de la fenêtre
#define BLOC_SIZE 25 //côté des blocs de tétrominos
#define GRID_W 10 //largeur de la grille de jeu
#define GRID_H 22 //hauteur de la grille de jeu
#define DEPART_X 3 //départ du nouveau tétro en X sur la grille
#define DEPART_Y 1 //départ du nouveau tétro en Y sur la grille
#define BLANC 8 //pour générer les blocs blancs
enum boutons {ON, OFF, JOUER, AIDE, OPTIONS, NIVEAU, REPRENDRE, QUITTER}; //liste des differents boutons du menu principal et du menu pause
//liste des différents boutons du menu options
enum butonsOptions {OK = 8, IROTATER, ISOFTD, ILEFT, IRIGHT, IHARDD, IROTATEL, IPAUSE, IGHOST, ICHANGE, VOLTHEMEM, VOLTHEMEP, VOLFXM, VOLFXP, RESET};
//liste des différents boutons de inputOptions
enum boutonsInputOptions {TOUCHE1 = 1, TOUCHE2, TOUCHE3, OKINPOPT};
//liste les différents types de blocs dans la grille (les blocs 'G' sont ceux qui appartiennent à la grille et qui ne peuvent bouger par input)
enum blocs {VIDE, JAUNE, CYAN, MAUVE, VIOLET, ORANGE, VERT, ROUGE, JAUNE_G, CYAN_G, MAUVE_G, VIOLET_G, ORANGE_G, VERT_G, ROUGE_G};
enum tetrominos {JAUNE_O, CYAN_I, MAUVE_T, VIOLET_J, ORANGE_L, VERT_S, ROUGE_Z}; //liste les différents tétrominos
enum positions {POS1, POS2, POS3, POS4}; //liste des positions possibles du tetromino
enum mouvements {ILLEGAL, LEGAL, KICK1, KICK2, KICK3, KICK4}; //liste des valeurs pouvant être retournées par testDeplacement
enum touches {ROTATER, SOFTD, LEFT, RIGHT, HARDD, ROTATEL, PAUSE, GHOST, CHANGE}; //liste des fonctions accessibles au clavier dans "partie()"
enum cheat {CHANGEZ = 9, CHANGES, CHANGET, CHANGEI, CHANGEO, CHANGEJ, CHANGEL}; //liste des fonctions de triche accessibles au clavier
enum coordonnes {X, Y}; //permet d'accéder à la position de des tetrominos
enum soundEv {NOEVENT, GAMESTART, GAMEOVER, LEVELUP, FALL, HARDDROP, HOLD, LOCKED, MOVELR, ROTATEFAIL, ROTATELR, SOFTDROP, TOUCHDOWN, TOUCHLR, LCSINGLE, LCDOUBLE, LCTRIPLE, LCTETRIS, STSPIN, STSPINSINGLE, STSPINDOUBLE, STSPINTRIPLE}; //liste des évènements déclenchants un son
enum soundOptions {SOUND, THEME, FX}; //liste des options de son

typedef struct packTetro packTetro;
struct packTetro
{
  int p_jaune_O[4][4][4];
  int p_cyan_I[4][4][4];
  int p_mauve_T[4][4][4];
  int p_violet_J[4][4][4];
  int p_orange_L[4][4][4];
  int p_vert_S[4][4][4];
  int p_rouge_Z[4][4][4];
};

packTetro *chargerTetrominos(); //on charge la valeur de chaque tetromino dans la structure "packTetro"
void destroyTetrominos(packTetro *tetros); //on détruit la structure pour libérer la mémoire

#endif
