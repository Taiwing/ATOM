#include<stdio.h>
#include<stdlib.h>
#include "data.h"

int main()
{
  Pile* pile = initialiser(); //on initialise la pile

  empiler(pile, 2);
  empiler(pile, 3);
  empiler(pile, 7);
  empiler(pile, 5);
  empiler(pile, 8);
  empiler(pile, 3);
  empiler(pile, 4);
  empiler(pile, 0);
  empiler(pile, 1);
  afficherPile(pile); //on affiche la pile

  for(int i = 0; i < 3; i++) //on exécute 3 fois cette boucle
  {
    printf("Je dépile %d\n", depiler(pile)); //on dépile le premier élément
  }

  printf("\n");
  afficherPile(pile); //on raffiche la pile

  return EXIT_SUCCESS;
}
