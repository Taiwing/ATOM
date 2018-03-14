#include<stdio.h>
#include<stdlib.h>
#include "mainV2.h"

int main()
{
  Coordonnees point; //on déclare une variable "point" de type "Coordonnes" sans mettre "struct" grâce à "typedef"
  point.x = 10; //on accède aux valeurs des variables de struct en mettant "nom_de_la_structure.nom_de_la_variable" (ou "variable.nomDeLaComposante")
  point.y = 20;

  return 0;
}
