#include<stdio.h>
#include<stdlib.h>

int main()
{
  int nombreDAmis = 0;
  printf("Comiben d'amis avez vous ? ");
  scanf("%d", &nombreDAmis);
  int *amis = malloc(nombreDAmis * sizeof(int));

  if(amis == NULL) //on teste si l'allocation a échoué
    exit(0); //"exit" arrête immédiatement le programe

  for(int i = 0; i < nombreDAmis; i++)
  {
    printf("Veuillez rentrer l'âge de votre ami %d: ", i+1);
    scanf("%d", &amis[i]);
  }

  printf("\n");

  for(int i = 0; i < nombreDAmis; i++)
    printf("Ami %d: %d ans\n", i+1, amis[i]);

  free(amis); //"free" libère la mémoire allouée précédemment

  return 0;
}
