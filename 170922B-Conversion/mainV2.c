#include<stdio.h>
#include<stdlib.h>

double conversion(double francs) //fonction de conversion en francs
{
  return francs / 6.55957;
}

int main ()
{
  double francs = 0;
  printf("Veuillez rentrer un prix en francs à convertir en euros: ");
  scanf("%lf", &francs); //l'utilisateur rentre le prix à convertir
  printf("%f F = %f €\n", francs, conversion(francs)); //on effectue la conversion via la fonction directement dans printf
  return 0;
}
