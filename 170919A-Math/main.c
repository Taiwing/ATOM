#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  printf("Bienvenue dan mon programe de math.\n");
  printf("Je vais ici tester un ensemble de fonctions mathématiques.\n");
  printf("Veuillez rentrer un nombre positif ou négatif,\net éventuellement décimal: ");
  double absolu = 0, dessus = 0, dessous = 0, puissance = 0, powa = 0, racecar = 0, nombre = 0;
  scanf("%lf", &nombre); //scanf fonctionne bizarrement quand on rajoute un "\n"
  absolu = fabs(nombre); //fabs est une fonfction de math.h revoyant la valeur absolue en variable double
  printf("La valeur absolue de %f est: %f\n", nombre, absolu); // ne pas oublier le type de variable auquel on a affaire
  dessus = ceil(nombre); //la fontion "ceil" arrondi au nombre entier supérieur
  //ne pas oublier de rajouter "-lm" dans la commande gcc pout lui faire inclure "math.h"
  printf("%f arrondi au nombre entier supérieur donne: %f\n", nombre, dessus);
  dessous = floor(nombre); //fait l'inverse de "ceil"
  printf("%f arrondi au nombre entier inférieur donne: %f\n", nombre, dessous);
  printf("Veuillez choisir à quelle puissance vous souhaitez élever %f: ", nombre);
  scanf("%lf", &powa);
  puissance = pow(nombre, powa); //permet d'élever "nombre" à la puissance "powa"
  printf("%f élevé à la puissace %f donne: %f\n", nombre, powa, puissance);
  racecar = sqrt(nombre);
  printf("La racine carrée de %f est égale à: %f\n", nombre, racecar);
  double expo = 0, loga = 0, loga10 = 0;
  expo = exp(nombre);
  loga = log(nombre);
  loga10 = log10(nombre);
  printf("Pour finir voici l'exponentielle de %f: %f\n", nombre, expo);
  printf("Son logarithme népérien: %f\n", loga);
  printf("Et son logarithme base 10: %f\n", loga10);
  return 0;
}
