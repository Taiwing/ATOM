#include<stdio.h>
#include<stdlib.h>

int main()
{
  int compteur = 0, nbFella = 0;
  printf("Beinvenue dans le programme d'autofellation informatique.\n");
  printf("Combien de fois voulez-vous vous faire fellationner aujourd'hui ? ");
  scanf("%d", &nbFella);
  /*la boucle "while" exécute les instructions entre
  crochets tant que sa condition est vrai*/
  do //exécute les instructions suivantes quelque soit le résultat du test de "while"
  {
    printf("Quel programmeur de génie !\n"); //avec un saut de ligne, c'est mieux xD
    compteur++; //on incrémente (augmente de 1) le compteur
  } while(compteur < nbFella); /*Réexécute les instructions de "do" tant que la condition
   est vrai. Ne pas oublier le point virgule après while sinon plantage.*/
  return 0;
}
