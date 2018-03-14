#ifndef DATA_H
#define DATA_H

//structure constituant chaque maillon de la chaîne de donnée qu'on va créer
typedef struct Element Element; //on crée l'alias de la structure qu'on va fabriquer
struct Element //puis on définit la structure
{
  int nombre; //on crée la variable int qu'on va stocker
  Element *suivant; //et un pointeur vers l'élément suivant de la liste
}; //ne pas oublier le ';' après la définition d'une structure

//structure gérant la chaîne
typedef struct Liste Liste;
struct Liste
{
  Element *premier; //pointe vers le premier maillon de la chaîne
  int nbElements; //variable indiquant la taille de la chaîne
};

Liste *initialisation(); //permet d'initialiser une chaîne de données (revoit un pointeur sur un structure liste)
void insertion(Liste *liste, int position, int nvNombre); //ajoute un élément à la position précisée dans la liste
void supression(Liste *liste, int position); //on supprime le premier élément de la liste
void afficherListe(Liste *liste); //affiche la liste (ouais sans dec)
int tailleChaine(Liste *liste); //récupère et renvoit la taille d'une chaîne
void detruireListe(Liste *liste); //détruit une liste

#endif
