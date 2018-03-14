#include<stdio.h> //NE PAS METTRE DE ; APRES CES LIGNES
#include<stdlib.h> //CE NE SONT PAS DES INSTRUCTIONS
//IL NE FAUT PAS NON PLUS OUBLIER LES .h BORDEL

int main()
{
  int resultat = 0;
  resultat = 5 + 3; //on attribue la valeur de 5+3 à la variable résultat
  printf("5 + 3 = %d\n", resultat); //on affiche la variable résultat
  double resultatDivision = 6 / 2;
  printf("6 / 2 = %f\n", resultatDivision); /*NE PAS OUBLIER QUE LORSQU'ON
  A AFFAIRE A UN NOMBRE DECIMAL IL FAUT METTRE %f DANS "printf" ET NON %d */
  resultatDivision = 7.0 / 3.0; /*Il faut mettre des nombres décimaux si on
  veut un résultat décimal, d'où le 7.0 et le 3.0*/
  printf("7 / 3 = %f\n", resultatDivision); //on essaye avec un résultat à virgule
  return 0;
}
