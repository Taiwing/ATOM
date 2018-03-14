#include<stdio.h>
#include<stdlib.h>
#include "mainV6.h"

int main()
{
  Coordonnees monPoint;
  Coordonnees *pointeur = &monPoint;

  initialiserCoordonnees(&monPoint);

  printf("Voici les coordonnées par défaut: x = %d, y = %d\n", monPoint.x, monPoint.y);

  monPoint.x = 10; //on travaille avec une variable, on utilise le "point"
  pointeur->y = 20; //on travaille avec un pointeur, on utilise la flèche

  printf("Voici les coordonnées initialisées par la variable et le pointeur: x = %d, y = %d\n", monPoint.x, monPoint.y);

  return 0;
}

void initialiserCoordonnees(Coordonnees *point)
{
  (*point).x = 0;
  (*point).y = 0;
}
