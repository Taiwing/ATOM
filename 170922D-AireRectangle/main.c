#include<stdio.h>
#include<stdlib.h>

double aireRectangle(double largeur, double hauteur) //on sépare les deux arguments de la fonction par une virgule
{
  return largeur * hauteur;
}

int main()
{
  double l = 0, h = 0;
  printf("Largeur du rectangle en cm: ");
  scanf("%lf", &l);
  printf("Hauteur du rectangle en cm: ");
  scanf("%lf", &h);
  printf("Votre rectangle a une aire de %f cm²\n", aireRectangle(l, h));
  return 0;
}
