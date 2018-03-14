#include<stdio.h>
#include<stdlib.h>

double conversion(double euros) //fonction de conversion en francs
{
  return euros * 6.55957;
}

int main ()
{
  double euros = 0;
  printf("Veuillez rentrer un prix en euros à convertir en francs: ");
  scanf("%lf", &euros); //l'utilisateur rentre le prix à convertir
  printf("%f € = %f F\n", euros, conversion(euros)); //on effectue la conversion via la fonction directement dans printf
  return 0;
}
