#include<stdio.h>
#include<stdlib.h>
#include "mainV5.h"

int main()
{
  //Coordonnes *point = NULL; //on crée un pointeur "point" qui pointe sur une structure de type "Coordonnes"

  Coordonnees monPoint;

  initialiserCoordonnees(&monPoint);

  printf("Voici les coordonnées par défaut: x = %d, y = %d\n", monPoint.x, monPoint.y);

  return 0;
}

void initialiserCoordonnees(Coordonnees *point)
{
  (*point).x = 0;
  (*point).y = 0;
}
