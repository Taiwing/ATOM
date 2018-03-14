#include<stdio.h>
#include<stdlib.h>
#include "main.h"

int main()
{
  Volume musique = MOYEN; //on initialise la variable "musique" de type "Volume" à la valeur "MOYEN"

  printf("La musique va se jouer à un niveau ");

  if(musique == FAIBLE)
    printf("faible.\n");
  else if(musique == MOYEN)
    printf("moyen.\n");
  else if(musique == FORT)
    printf("fort.\n");

  return 0;
}
