#include<stdio.h>
#include<stdlib.h>

int main()
{
  int compteur, nbFella = 0;
  printf("Beinvenue dans le programme d'autofellation informatique.\n");
  printf("Combien de fois voulez-vous vous faire fellationner aujourd'hui ? ");
  scanf("%d", &nbFella);
  /*Dans la première partie des parenthèses de la boucle "for", on initie la valeur de "compteur".
  Dans la deuxième on indique la condition d'exécution des instructions de la boucle. Puis, dans la
  troisième on met l'incrémentation de la variable choisie.*/
  for(compteur = 0; compteur < nbFella; compteur++) //la boucle "for" est plus condensée que la boucle while
  {
    printf("Quel programmeur de génie !\n"); //avec un saut de ligne, c'est mieux xD
  }
  return 0;
}
