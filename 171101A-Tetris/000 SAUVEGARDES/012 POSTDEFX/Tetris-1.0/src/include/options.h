#ifndef OPTIONS_H
#define OPTIONS_H

//fonctions du menu de configuration
void menuOptions(gameScreen *screen, gameConfig *config, elements *elem, packOptions *images, packSons *sons);
int estSurUnBoutonOptions(Liste *lElem, int x, int y); //va déterminer où se trouve la souris
void afficherOptions(gameScreen *screen, packOptions *images, elements *elem, int bouton, int vol[2]); //va afficher le menu options
float tradInt(int integer); //va traduire le nombre affiché en float pour la fonction jouerSon
int tradFloat(float floater); //va traduire le volume voulu en int pour la fonction d'affichage
//va gérer l'input pour le changement de touche
void inputOptions(gameScreen *screen, int bouton, gameConfig *config, elements *elem, packOptions *images);
//va afficher la fenêtre d'input du menu options
void afficherInputOptions(gameScreen *screen, packOptions *images, elements * elem, int bouton, int touche, int zoneInput, gameConfig *config, int input[3]);
void strToucheZoneInput(int touche, char str[30]); //va convertir la touche choisie en string
int estSurUnBoutonInputOptions(Liste *lElem, int x, int y); //va regarder où se trouve la souris
void chargerListeElemFondOptions(gameScreen *screen, elements *elem, Liste *lElem); //va charger la liste de coordFloat modifiés
void chargerListeElemInputOptions(gameScreen *screen, elements *elem, Liste *lElem); //same mais pour inputOptions

#endif
