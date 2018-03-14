#include<stdio.h>
#include<stdlib.h>
#include "data.h"

Pile *initialiser()
{
  Pile *pile = malloc(sizeof(*pile)); //on crée le pointeur vers la pile crée
  pile->premier = NULL; //on initialise le premier pointeur de la pile à "NULL" vu qu'elle est vide
  return pile; //on renvoit la pile crée
}

void empiler(Pile *pile, int nvNombre)
{
  //on crée le nouvel élément qu'on va empiler
  Element *nvElement = malloc(sizeof(*nvElement));

  if(pile == NULL || nvElement == NULL) //on vérifie que tout s'est bien passé
    exit(EXIT_FAILURE);

  //puis on le met au-dessus de la pile
  nvElement->nombre = nvNombre; //on lui attribue la valeur choisie
  nvElement->suivant = pile->premier; //on fait pointer le nouvel élément sur le premier de la pile
  pile->premier = nvElement; //puis le premier sur le nouvel élément
}

int depiler(Pile *pile)
{


  Element *elementDepile = pile->premier; //on récupère le premier élément de la pile
  int nombreDepile = 0; //on initie le nombre qu'on va renvoyer à 0

  if(elementDepile != NULL) //si la pile n'est pas vide
  {
    nombreDepile = elementDepile->nombre; //on récupère le nombre contenu par le premier élément
    pile->premier = elementDepile->suivant; //on définit le premier de la pile par l'élément sous celui qu'on enlève
    free(elementDepile); //on efface l'élément qu'on enlève
  }

  return nombreDepile; //on renvoit le contenu de l'élément qu'on enlève
}

void afficherPile(Pile *pile)
{
  if(pile == NULL) //s'il n'y a pas de pile
    exit(EXIT_FAILURE);

  //on crée un pointeur sur l'élément qu'on va afficher
  Element *elementAffiche = pile->premier; //on l'initie par le premier de la pile

  while(elementAffiche != NULL) //tant qu'on est pas au bout de la pile
  {
    printf("%d\n", elementAffiche->nombre); //on affiche le nombre de l'élément pointé
    elementAffiche = elementAffiche->suivant; //puis on descend d'un élément dans la pile
  }

  printf("\n"); //puis on affiche "NULL" pour signifier la fin de la pile
}
