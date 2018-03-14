#ifndef DEF_FONCTIONS
#define DEF_FONCTIONS

#include "main.h"
#include "affichePendu.h"
#include<string.h> //pour manipuler les chaines de caractères comme on veut
#include<time.h> //pour faire un nombre aléatoire
#include<ctype.h> //pour la fontction "toupper" permettant de mettre un caractère en majuscule
#define TAILLE_MAX 40

char *motAleatoire(); //choisit un mot aléatoire dans un fichier
char *motChoisi(); //l'un des joueurs rentre le mot mystère
char lireCaractere(); //fonction prenant et traitant le caractère rentré par l'utilisateur
int essaiReussi(const char caractere, const char* motMystere); //renvoit un boléen
void afficheCarac(const char caractere, const char* motMystere, char* motJoueur); //affiche les caractères devinés
int devine(const char* motJoueur); //renvoit un boléen
void partie(int deuxJ); //contient tout le code pour une partie
int rejouer(); //affiche un menu demandant si on veut rejouer ou pas et renvoit un boléen
int deuxJoueurs(); //affiche un menu demandant si on veut le mode deux joueurs ou pas
void coupsRestants(); //affcihe le pendu et modifie l'image à chaque fois qu'une erreur est commise

#endif //sert à eviter de d'inclure le fichier "fonctions.h" deux fois
