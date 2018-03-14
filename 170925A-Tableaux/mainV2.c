#include<stdio.h>
#include<stdlib.h>

int main()
{
  int tableau[4]; //grâce aux crochets on crée un tableau de 4 cases stockant des valeurs "int"

  printf("test de la valeur de 'tableau' une fois déclaré: %d\n", tableau);
  //ici "tableau" est traité comme un pointeur qui renvoit l'adresse de la prmière case du tableau

  tableau[0] = 10; //on affecte la vaeur 10 à la première case du tableau (indexée par un 0)
  tableau[1] = 23;
  tableau[2] = 505;
  tableau[3] = 8; //bien que la tableau fasse 4 cases, la dernière valeur est indexée en 3 vu que la prmière l'est à 0

  printf("valeur de la première case du tableau: %d\n", tableau[0]); //on affiche la valeur de la première case
  printf("valeur de la première case du tableau: %d\n", *tableau); //on affiche la même valeur qu'au-dessus mais en utilisant une autre notation
  printf("valeur de la deuxième case du tableau: %d\n", *(tableau +1)); //ici on ajoute "1" à l'adresse de la variable pointée, donc on affiche la deuxième case
  printf("valeur de la quatrième case du talbeau: %d\n", *(tableau + 3)); //ici "+3", donc quatrième case

  int taille = 7;
  int tableau2[taille];
  tableau2[6] = 333;
  printf("test du tableau à taille dynamique: %d\n", *(tableau2 + 6));

  /*On peut en conclure que le symbole "*" signifie, dans ce contexte, "prend la valeur de la variable qui se trouve à l'adresse: ".
  Donc "*x" signifie "prend la valeur de la variable pointée par x" (x doit donc être une adresse, ou un pointeur). On voit aussi que
  "*(x+1)" signifie "prend la valeur de la variable située à l'adresse x+1". Dans les tableaux, les variables sont stockées à des
  adresses consécutives, les unes après les autres. L'adresse du tableau est en réalité celle de la première variable de celui-ci.*/

  return 0;
}
