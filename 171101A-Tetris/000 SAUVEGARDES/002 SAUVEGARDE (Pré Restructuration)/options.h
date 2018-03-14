#ifndef OPTIONS_H
#define OPTIONS_H

//structure de configuration du son
typedef struct soundConfig soundConfig;
struct soundConfig
{
  bool soundOnOff[3]; //va dire si le son général, celui du thème et des FX sont activés ou non
  float volume[2]; //va indiquer le volume de thème et des FX
};

//fonctions de soundConfig
soundConfig *initialiserConfigSon(); //va créer la structure de configuration sonore et lire le ficheir de config s'il y en a un
void resetSoundConfig(soundConfig *sound); //va remettre les valeurs par défaut dans la structure et dans le fichier s'il y en a un
void destroySoundConfig(soundConfig *sound); //va détruire la structure de configuration sonore

//structure de configuration générale
typedef struct gameConfig gameConfig;
struct gameConfig
{
  //configuration du son
  soundConfig *sound;

  //va stocker ls contrôles du jeu
  int keyMap[9][3];

  //autres paramètres
  bool cheatFunctions;
};

//fonctions de gameConfig
gameConfig *initialiserConfigJeu(); //va créer la structure de configuration du jeu et lire le ficheir de config s'il y en a un
void resetGameConfig(gameConfig *config); //va remettre les valeurs par défaut dans la structure et dans le fichier s'il y en a un
void destroyGameConfig(gameConfig *config); //va détruire la structure de configuration du jeu

//fonctions du menu de configuration
void menuOptions(ALLEGRO_DISPLAY *fenetre, gameConfig *config, elementsFondOptions *elem, packOptions *images);
int estSurUnBoutonOptions(elementsFondOptions *elem, int x, int y); //va déterminer où se trouve la souris
void afficherOptions(packOptions *images, elementsFondOptions *elem, int bouton, int vol[2]); //va afficher le menu options
float tradInt(int integer); //va traduire le nombre affiché en float pour la fonction jouerSon
int tradFloat(float floater); //va traduire le volume voulu en int pour la fonction d'affichage

#endif
