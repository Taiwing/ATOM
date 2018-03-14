#ifndef DATA_LIST_H
#define DATA_LIST_H

//structure qui va être stockée dans la chaîne
typedef struct coordFloat coordFloat;
struct coordFloat
{
  float x; //coordonnée x du point d'origine
  float y; //coordonnée y du point d'origine
  float x2; //coordonnée x du point de fin
  float y2; //coordonnée y du point de fin
  float w; //largeur
  float h; //hauteur
  float t; //épaisseur des traits
};

//structure constituant chaque maillon de la chaîne de donnée qu'on va créer
typedef struct ElementL ElementL; //on crée l'alias de la structure qu'on va fabriquer
struct ElementL //puis on définit la structure
{
  coordFloat *rect; //on crée la variable la structure coord qu'on va stocker
  ElementL *suivant; //et un pointeur vers l'élément suivant de la liste
}; //ne pas oublier le ';' après la définition d'une structure

//structure gérant la chaîne
typedef struct Liste Liste;
struct Liste
{
  ElementL *premier; //pointe vers le premier maillon de la chaîne
  int nbElements; //variable indiquant la taille de la chaîne
};

//fonctions de gestion de la liste
Liste *initialisationListe(); //permet d'initialiser une chaîne de données (revoit un pointeur sur un structure liste)
void insertionL(Liste *liste, int position, coordFloat *nvRect); //ajoute un élément à la position précisée dans la liste
void supressionL(Liste *liste, int position); //on supprime le premier élément de la liste
int tailleChaine(Liste *liste); //récupère et renvoit la taille d'une chaîne
void detruireListe(Liste *liste); //détruit une liste
void dechargerListe(Liste *liste); // on vide la liste, ne laissant que le prmier élément, vide

#endif
