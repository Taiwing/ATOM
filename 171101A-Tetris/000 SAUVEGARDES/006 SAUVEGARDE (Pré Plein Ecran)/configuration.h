#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "main.h"

//structure de configuration du son
typedef struct soundConfig soundConfig;
struct soundConfig
{
  bool soundOnOff[3]; //va dire si le son général, celui du thème et des FX sont activés ou non
  float volume[2]; //va indiquer le volume de thème et des FX
};

//structure de configuration générale
typedef struct gameConfig gameConfig;
struct gameConfig
{
  //configuration du son
  soundConfig *sound;

  //va stocker ls contrôles du jeu
  int keyMap[16][3];

  //autres paramètres
  bool cheatFunctions;
};

//fonctions de gameConfig
gameConfig *initialiserConfigJeu(); //va créer la structure de configuration du jeu
void chargerGameConfig(gameConfig *config); //va lire le fichier de configuration et charger la structure
void enregistrerGameConfig(gameConfig *config); //va enregistrer la config actuelle dans le fichier de configuration
void resetGameConfig(gameConfig *config); //va remettre les paramètres du jeu à leur valeur par défaut
void destroyGameConfig(gameConfig *config); //va détruire la structure de configuration du jeu

#endif
