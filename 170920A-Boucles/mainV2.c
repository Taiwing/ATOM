#include<stdio.h>
#include<stdlib.h>

int main()
{
  int compteur = 0;
  /*la boucle "while" exécute les instructions entre
  crochets tant que sa condition est vrai*/
  while(compteur < 10) //tant que la valeur de "compteur" est inférieure à 10
  {
    printf("Quel programmeur de génie !\n"); //avec un saut de ligne, c'est mieux xD
    compteur++; //on incrémente (augmente de 1) le compteur
    printf("La variable compteur vaut %d\n", compteur);
  }
  return 0;
}
