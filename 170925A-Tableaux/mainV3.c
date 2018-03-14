#include<stdio.h>
#include<stdlib.h>

int main()
{
  int tableau[4]; //grâce aux crochets on crée un tableau de 4 cases stockant des valeurs "int"

  tableau[0] = 10; //on affecte la vaeur 10 à la première case du tableau (indexée par un 0)
  tableau[1] = 23;
  tableau[2] = 505;
  tableau[3] = 8; //bien que la tableau fasse 4 cases, la dernière valeur est indexée en 3 vu que la prmière l'est à 0

  for(int i = 0; i < 4; i++)
    printf("valeur de la case %d: %d\n", i+1, tableau[i]);

  for(int i = 0; i < 4; i++) //on réutilise la même variable que pour la boucle d'au-dessus, mais elle n'existe que pour le temps de la boucle, donc on la réinitie
  {
    tableau[i] = 0; //on pourrait aussi mettre: "*(tableau + i) = 0"
    printf("la case %d a désormais la valeur: %d\n", i+1, *(tableau + i)); //ici on envoit la valeur de la case via un pointeur, comme on aurait pu faire au-dessus
  }

  /*On peut en conclure que le symbole "*" signifie, dans ce contexte, "prend la valeur de la variable qui se trouve à l'adresse: ".
  Donc "*x" signifie "prend la valeur de la variable pointée par x" (x doit donc être une adresse, ou un pointeur). On voit aussi que
  "*(x+1)" signifie "prend la valeur de la variable située à l'adresse x+1". Dans les tableaux, les variables sont stockées à des
  adresses consécutives, les unes après les autres. L'adresse du tableau est en réalité celle de la première variable de celui-ci.*/

  return 0;
}
