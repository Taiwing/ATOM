#ifndef SON_H
#define SON_H
#include "data_files.h" //pour la file d'évènements du jeu

//structure de sons
typedef struct packSons packSons;
struct packSons
{
  ALLEGRO_SAMPLE *themeSample;
  ALLEGRO_SAMPLE *gamestartSample;
  ALLEGRO_SAMPLE *gameoverSample;
  ALLEGRO_SAMPLE *levelupSample;
  ALLEGRO_SAMPLE *fallSample;
  ALLEGRO_SAMPLE *harddropSample;
  ALLEGRO_SAMPLE *holdSample;
  ALLEGRO_SAMPLE *lockedSample;
  ALLEGRO_SAMPLE *movelrSample;
  ALLEGRO_SAMPLE *rotatefailSample;
  ALLEGRO_SAMPLE *rotatelrSample;
  ALLEGRO_SAMPLE *softdropSample;
  ALLEGRO_SAMPLE *touchdownSample;
  ALLEGRO_SAMPLE *touchlrSample;
  ALLEGRO_SAMPLE *lcsingleSample;
  ALLEGRO_SAMPLE *lcdoubleSample;
  ALLEGRO_SAMPLE *lctripleSample;
  ALLEGRO_SAMPLE *lctetrisSample;
  ALLEGRO_SAMPLE *stspinSample;
  ALLEGRO_SAMPLE *stspinsingleSample;
  ALLEGRO_SAMPLE *stspindoubleSample;
  ALLEGRO_SAMPLE *stspintripleSample;

  ALLEGRO_SAMPLE_INSTANCE *theme;
  ALLEGRO_SAMPLE_INSTANCE *gamestart;
  ALLEGRO_SAMPLE_INSTANCE *gameover;
  ALLEGRO_SAMPLE_INSTANCE *levelup;
  ALLEGRO_SAMPLE_INSTANCE *fall;
  ALLEGRO_SAMPLE_INSTANCE *harddrop;
  ALLEGRO_SAMPLE_INSTANCE *hold;
  ALLEGRO_SAMPLE_INSTANCE *locked;
  ALLEGRO_SAMPLE_INSTANCE *movelr;
  ALLEGRO_SAMPLE_INSTANCE *rotatefail;
  ALLEGRO_SAMPLE_INSTANCE *rotatelr;
  ALLEGRO_SAMPLE_INSTANCE *softdrop;
  ALLEGRO_SAMPLE_INSTANCE *touchdown;
  ALLEGRO_SAMPLE_INSTANCE *touchlr;
  ALLEGRO_SAMPLE_INSTANCE *lcsingle;
  ALLEGRO_SAMPLE_INSTANCE *lcdouble;
  ALLEGRO_SAMPLE_INSTANCE *lctriple;
  ALLEGRO_SAMPLE_INSTANCE *lctetris;
  ALLEGRO_SAMPLE_INSTANCE *stspin;
  ALLEGRO_SAMPLE_INSTANCE *stspinsingle;
  ALLEGRO_SAMPLE_INSTANCE *stspindouble;
  ALLEGRO_SAMPLE_INSTANCE *stspintriple;
};

//fonctions sonores
packSons *chargerSon(); //va être appelée une fois au début du programme et va charger les addons et les fichiers de son
void jouerSon(bool sound[3], packSons *sons, File *soundEv); //va jouer le son du jeu si le joueur l'a activé
void libererMemoireSon(packSons *sons); //va être appelée une fois à la fin du programme et va libérer la mémoire

#endif
