#include<stdio.h>
#include<stdlib.h>
#include "include/data_files.h"

File *initialiser()
{
  File *file = malloc(sizeof(*file)); //on crée le pointeur vers la file crée
  file->premier = NULL; //on initialise le premier pointeur de la file à "NULL" vu qu'elle est vide
  return file; //on renvoit la file crée
}

void enfiler(File *file, int nvNombre)
{
  Element *nvElement = malloc(sizeof(*nvElement)); //on crée un pointeur vers le nouvel élément

  if(file == NULL || nvElement == NULL) //si l'une des deux initialisations n'a pas marché
    exit(EXIT_FAILURE);

  nvElement->nombre = nvNombre; //on initie la valeur du nouvel élément à ce qu'à rentré le singe
  nvElement->suivant = NULL; //puis on met le pointeur "suivant" à "NULL" vu qu'il est le dernier de la file

  if(file->premier == NULL) //si la file est vide
  {
    file->premier = nvElement; //alors on place le nouvel élément en premier
  }
  else //si la file n'est pas vide
  {
    //on parcourt la file du début jusqu'à atteindre le dernier élément
    Element *dernier = file->premier; //on crée un pointeur pour parcourir la file
    while(dernier->suivant != NULL) //on s'arrête quand on a trouvé le dernier de la file
    {
      dernier = dernier->suivant; //on se décale d'une position dans la file
    }
    dernier->suivant = nvElement; //on place finalement le nouvel élément après le dernier
  }
}

int defiler(File *file)
{
  if(file == NULL) //si la file n'existe pas
    exit(EXIT_FAILURE);

  int nombreDefile = 0; //on initie la valeur qu'on va renvoyer
  if(file->premier != NULL) //si la file n'est pas vide
  {
    Element *aDefiler = file->premier; //on crée un pointeur vers l'élément qu'on va retirer
    nombreDefile = aDefiler->nombre; //on récupère le nombre qu'on va renvoyer
    file->premier = aDefiler->suivant; //l'élément suivant celui qu'o ndéfile passe en premier
    free(aDefiler); //puis on supprime l'élément défilé de la mémoire
  }

  return nombreDefile; //puis on revoit la valeur défilée
}

void afficherFile(File *file)
{
  if(file == NULL) //si la pile n'existe pas
    exit(EXIT_FAILURE);

  Element *elementAffiche = file->premier; //on récupère le premier élément à afficher

  while(elementAffiche != NULL) //tant qu'il y a des éléments à afficher
  {
    printf("%d ", elementAffiche->nombre); //on affiche le nombre contenu dans l'élément
    elementAffiche = elementAffiche->suivant; //puis on passe à l'élément suivant
  }
  printf("\n");
}
