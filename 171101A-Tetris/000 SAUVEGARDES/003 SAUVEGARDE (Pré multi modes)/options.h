#ifndef OPTIONS_H
#define OPTIONS_H

//fonctions du menu de configuration
void menuOptions(ALLEGRO_DISPLAY *fenetre, gameConfig *config, elementsFondOptions *elem, packOptions *images, packSons *sons);
int estSurUnBoutonOptions(elementsFondOptions *elem, int x, int y); //va déterminer où se trouve la souris
void afficherOptions(packOptions *images, elementsFondOptions *elem, int bouton, int vol[2]); //va afficher le menu options
float tradInt(int integer); //va traduire le nombre affiché en float pour la fonction jouerSon
int tradFloat(float floater); //va traduire le volume voulu en int pour la fonction d'affichage
//va gérer l'input pour le changement de touche
void inputOptions(ALLEGRO_DISPLAY *fenetre, int bouton, gameConfig *config, elementsFondOptions *elem, packOptions *images);
//va afficher la fenêtre d'input du menu options
void afficherInputOptions(packOptions *images, elementsFondOptions * elem, int bouton, int touche, int zoneInput, gameConfig *config, int input[3]);
void strToucheZoneInput(int touche, char str[30]); //va convertir la touche choisie en string
int estSurUnBoutonInputOptions(elementsFondOptions *elem, int x, int y); //va regarder où se trouve la souris

#endif
