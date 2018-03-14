#include<stdio.h>
#include<stdlib.h>
#include"tableauxV6.h"

int main()
{
  int tableau[5] = {1, 2, 3, 7, 2};

  afficheTableau(tableau, 5);

  printf("La somme de toutes les case du tableau est: %d\n", sommeTableau(tableau, 5));

  printf("La moyenne des valeurs du tableau est: %d\n", moyenneTableau(tableau, 5));

  int tableau2[6];
  copierTableau(tableau, 5, tableau2, 6);

  printf("Ici on a copié le premier tableau dans un deuxième:\n");
  afficheTableau(tableau2, 6);

  maximumTableau(tableau, 5, 2);
  printf("Ici on a remplacé toutes les valeurs du premier tableau dépassant 2 par 0:\n");
  afficheTableau(tableau, 5);

  ordonnerTableau(tableau2, 6);
  printf("Ici on a mis les valeurs du deuxième tableau dans l'ordre croissant:\n");
  afficheTableau(tableau2, 6);

  return 0;
}
