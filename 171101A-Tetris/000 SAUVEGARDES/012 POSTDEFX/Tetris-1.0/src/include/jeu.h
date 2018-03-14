#ifndef JEU_H
#define JEU_H
#include "main.h"
#include "fenetre.h"
#include "pause.h"
#include "score.h"
#include "son.h"
#include "options.h"
/*jeu.h: fichier inclut dans les headers de partie, contient les définitions de toutes les fonctions nécessaires à une partie*/

//structure des données du jeu
typedef struct gameData gameData;
struct gameData
{
  //données du joueur
  int niveau;
  int score;
  int lignes;
  int nbLignes; //va compter le nombre de lignes disparues s'il y en a
  int vitesse;

  //données tétrominos
  packTetro *tetros;
  int grille[GRID_W][GRID_H];
  int tetroActuel[4][5];
  int tetroSuivant[4][5];
  int sac[7]; //contient les 7 prochains tétrominos tirés au sort
  int nbTetro; //indique où on en est dans le sac

  //données de combo
  int dernierCoup;
  int comboCount;

  //file d'évènements du jeu pour les bruitages et l'affichage
  File *gameEv;
  int gameEvent; //va contenir l'évènement actuel pour l'envoyer aux fonctions d'affichage et de son
  bool afficherGameEvent[9]; //va dire à la fonction afficherEvenement s'il faut l'afficher ou non
  int timerAfficheEvent; //va compter le nombre de ticks que va durer l'affichage de l'évènement

  //gestion des déplacements
  int deplacement; //va recueillir la valeur renvoyée par deplacerTetro
  int timerVitesse;
  int timerLateral;
  int timerAnimDisp;
  int timerLock;

  //booléens de la partie
  bool redraw; //pour redessiner la partie quand 1/60s s'est écoulé
  bool continuer; //pour la boucle principale
  bool key[16]; //gestion de l'input clavier
  bool perdu;
  bool victoire;
  bool nextTetro;
  bool legalInput;
  bool lComplete;
  bool animDisp;
  bool ghostPieceOnOff;
  bool holdPieceOn;
  bool TSpin;
  bool lc;
};

//fonctions de gameData
gameData *initialiserGameData(int niveauChoisi); //va générer la structure de données du jeu
void destroyGameData(gameData *data); //va supprimer la structure de données du jeu

//fonction de jeu
void selectionAleatoireTetromino(gameData *data); //va sélectionner le prochain tétromino
void randomGenerator(int sac[7]); //va sélectionner aléatoirement les 7 prochains tétrosminos
bool placerTetro(gameData *data); //on met le tetroSuivant dans tetroActuel, et on le place dans la grille
//va déplacer la pièce si le mouvement est légal (et renvoyer "nextTetro = true" s'il faut changer de pièce)
int deplacerTetro(int mouvement, gameData *data);
//test le déplacement dans "deplacerPiece" et renvoit 0, 1 ou 2 (0: interdit, 1: légal, 2: illégal et pièce suivante)
int testDeplacement(int mouvement, int grille[GRID_W][GRID_H], int tetroActuel[4][5], packTetro *tetros);
//va tester si le tétro est sur le point de se bloquer
bool lockTest(gameData *data);
//va bloquer le tétromino dans la grille
void lockTetro(gameData *data);
//va vérifier s'il y a une ou plusieurs lignes complétées
bool ligneComplete(gameData *data);
//va enlever les lignes complètes, et faire descendre celles du dessus s'il y en a
int enleverLignes(gameData *data);
void scoring(int action, gameData *data); //va calculer le score
void leveling(gameData *data); //se charge du changement de niveau et détermine la vitesse en fonction
void ghostPiece(packPartie *images, gameData *data); //va afficher le tétro fantôme
bool holdPiece(gameData *data); //va retenir le tétro actuel
 //va déclencher un compte à rebours de trois secondes
void troisDeuxUn(gameScreen *screen, packPartie *images, elements *elem, int pause, int niveau, int score, int lignes);
//va l'afficher
void afficherTroisDeuxUn(gameScreen *screen, packPartie *images, elements *elem, int pause, int niveau, int score, int lignes, int temps);
bool TSpinTest(gameData *data); //va dire s'il y a T-Spin ou non
bool testTouchLR(gameData *data); //va indiquer si le tétromino actuel touche un bloc ou un mur
//va exécuter les actions correspondant à l'input du joueur
void gameInput(gameData *data, gameScreen *screen, elements *elem, packPartie *images, ALLEGRO_EVENT_QUEUE *event_queue_partie, ALLEGRO_TIMER *timer_partieMarathon, packSons *sons, gameConfig *config);
//va vérifier si la touche appuyée correspond à une touche de jeu, et exécuter l'action voulue en fonction
void inputKeyDown(int inputConfig[16][3], gameData *data, int key, gameConfig *config);
//va vérifier si la touche qui n'est plus appuyée correspond à une touche de jeu, et exécuter l'action voulue en fonction
void inputKeyUp(int inputConfig[16][3], gameData *data, int key);
void afficherEvenement(gameData *data, elements *elem); //va afficher l'évènement

//cheat Functions
void changeTetro(int tetro, gameData *data, gameConfig *config); //va sélectionner le prochain tétromino

//fonctions SPRINT & ULTRA
void speed(gameData *data); //se charge de déterminer la vitesse en fonction du niveau choisi

#endif
