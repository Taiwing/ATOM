#include<stdio.h>
#include<stdlib.h>

void aireRectangle(double largeur, double hauteur);
/*On a ici le prototype de la fonction "aireRectangele" avec un point virgule
à ne pas oublier qui permet de la placer n'importe où dans le code source,
y compris après la fonction "main". A noter qu'il est ici facultatif d'écrire
le nom des variables, on aurait donc simplement pu mettre:
"void aireRectangle(double, double);"*/

int main()
{
  double l = 0, h = 0;
  printf("Largeur du rectangle en cm: ");
  scanf("%lf", &l);
  printf("Hauteur du rectangle en cm: ");
  scanf("%lf", &h);
  aireRectangle(l, h);
  return 0;
}

void aireRectangle(double largeur, double hauteur) //on sépare les deux arguments de la fonction par une virgule
{
  double aire = largeur * hauteur;
  printf("Votre rectangle a une aire de %f cm²\n", aire);
}
