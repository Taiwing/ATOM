#include<stdio.h>
#include<stdlib.h>
#include "data.h"

Liste *initialisation()
{
  Liste *liste = malloc(sizeof(*liste)); //on crée un pointeur vers la structure de contrôle
  Element *element = malloc(sizeof(*element)); //puis vers le premier élément de la liste

  if(liste == NULL || element == NULL) //si l'un des deux pointeurs n'a pas été initialisé correctement
    exit(EXIT_FAILURE); //on quitte le programme

  element->nombre = 0; //on initie à 0 la valeur int du premier élément
  element->suivant = NULL; //puis le pointeur "suivant" à "NULL", ce qui en fait donc le dernier élément de la chaîne
  liste->premier = element; //on indique à la structure "liste" que "element" est le premier maillon de la chaîne
  liste->nbElements = 1; //on indique que la chaîne contient 1 élément

  return liste; //puis on retourne un pointeur vers la structure de contrôle
}

void insertion(Liste *liste, int position, int nvNombre)
{
  Element *nvElement = malloc(sizeof(*nvElement)); //on crée l'élément à ajouter

  if(liste == NULL || nvElement == NULL) //si l'un des deux pointeurs n'a pas été initialisé correctement
    exit(EXIT_FAILURE); //on quitte le programme

  if(liste->nbElements >= position) //si la position demandée existe
  {
    //on incrémente le nombre d'éléments dans "liste"
    liste->nbElements++;

    //on place tout d'abord le nouvel élément en première position de la liste
    nvElement->suivant = liste->premier; //on fait du premier élément de la liste le suivant du nouveau
    liste->premier = nvElement; //puis on fait du nouveau le premier élément de la liste

    //on affecte la valeur voulue au nouvel élément
    nvElement->nombre = nvNombre;

    if(position > 0) //si le nouvel élément ne doit pas se trouver en première position
    {
      //on fait un pointeur sur la position précédent le nouvel élément
      Element *posPrec = liste->premier;

      //on déplace le nouvel élément jusqu'à la position voulue
      for(int i = 0; i < position; i++)
      {
        if(i == 0) //si c'est la première fois qu'on exécute la boucle
        {
          //on redéfinit le premier élément de la liste comme il était avant la fonction
          liste->premier = nvElement->suivant; //on remet le précédent en premier dans la liste
          posPrec = liste->premier;
          nvElement->suivant = nvElement->suivant->suivant; //on fait pointer le "suivant" du nouvel élément sur celui que pointait l'ex-premier
          posPrec->suivant = nvElement; //puis on met le nvElement après le premier
        }
        else //sinon
        {
          posPrec->suivant = nvElement->suivant; //on décale "suivant" d'un "cran vers la gauche"
          posPrec = posPrec->suivant; //on re définit la position précédente comme étant celle qui suivait le nouvel élément
          nvElement->suivant = nvElement->suivant->suivant; //on définit la nouvelle position d'après comme celle d'après la suivante
          posPrec->suivant = nvElement; //puis on place le nouvel élément après la position précédente
        }
      }
    }
  }
}

void supression(Liste *liste, int position)
{
  if(liste == NULL) //si le pointeur "liste" ne renvoit rien
    exit(EXIT_FAILURE); //on quitte le programme

  if(liste->premier != NULL && liste->nbElements > position) //si la liste n'est pas vide et que la position à effacer existe
  {
    Element *aSupprimer = liste->premier; //on définit l'élement qu'on va supprimer
    Element *posPrec = NULL;

    if(position > 0) //si l'élément à supprimer n'est pas le premier de la liste
    {
      for(int i = 0; i < position; i++)
      {
        posPrec = aSupprimer; //on enregistre la position précédente
        aSupprimer = posPrec->suivant; //l'élément à supprimer devient celui qui suit la position précédente
      }
    }
    else //sinon
    {
      liste->premier = aSupprimer->suivant; //le premier élément de la liste devient celui qui suivait l'élément qu'on supprime
    }
    if(position != 0)
      posPrec->suivant = aSupprimer->suivant; //on relie la position précédente à celle suivant l'élément supprimé pour refermer la chaîne

    free(aSupprimer); //on libère la mémoire pointée par "aSupprimer", ce qui supprime les données
    liste->nbElements--; //on décrémente le nombre d'éléments dans la liste
  }
}

void afficherListe(Liste *liste)
{
  if(liste == NULL) //si le pointeur "liste" ne renvoit rien
    exit(EXIT_FAILURE); //on quitte le programme

  Element *elementAffiche = liste->premier; //on crée un pointeur vers le premier élément de la liste

  while(elementAffiche != NULL) //tant qu'on a des éléments a afficher dans la liste
  {
    printf("%d -> ", elementAffiche->nombre); //on affiche la a valeur de l'élément dans la console
    elementAffiche = elementAffiche->suivant; //on passe à l'élément suivant de la liste
  }

  printf("NULL\n"); //signale la fin de la liste
}

int tailleChaine(Liste *liste)
{
  return liste->nbElements;
}

void detruireListe(Liste *liste)
{
  int taille = tailleChaine(liste); //on récupère la taille de la chaîne

  //d'abord on supprime tous les éléments de la chaîne un à un
  for(int i = 0; i < taille; i++)
  {
    supression(liste, 0);
  }

  free(liste); //on supprime l'élément de contrôle
}
