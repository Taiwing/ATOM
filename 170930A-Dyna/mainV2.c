#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *pointeur = malloc(sizeof(int)); //"malloc" (memoryallocation) alloue un nombre d'octets donné en mémoire et renvoie un pointeur dessus

  if(pointeur != NULL) //on teste si l'allocation a réussi
  {
    *pointeur = 18; //on donne une valeur à la variable qu'on veut créer

    printf("la variable int allouée manuellement à l'adresse %p vaut %d\n", pointeur, *pointeur);

    free(pointeur); //"free" libère la mémoire allouée précédemment
  }
  else
    printf("ERREUR: l'allocation de mémoire a échoué\n");

  return 0;
}
