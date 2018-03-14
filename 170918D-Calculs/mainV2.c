#include<stdio.h> //NE PAS METTRE DE ; APRES CES LIGNES
#include<stdlib.h> //CE NE SONT PAS DES INSTRUCTIONS
//IL NE FAUT PAS NON PLUS OUBLIER LES .h BORDEL

int main()
{
  int resultat = 0;
  resultat = 5 + 3; //on attribue la valeur de 5+3 à la variable résultat
  printf("5 + 3 = %d\n", resultat); //on affiche la variable résultat
  resultat = 6 / 2;
  printf("6 / 2 = %d\n", resultat);
  resultat = 7 / 3;
  printf("7 / 3 = %d\n", resultat); //on essaye avec un résultat à virgule
  return 0;
}
