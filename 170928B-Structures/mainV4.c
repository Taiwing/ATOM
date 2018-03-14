#include<stdio.h>
#include<stdlib.h>
#include "mainV4.h"

int main()
{
  Personne joueurs[2]; //on crée un tableau de "personnes"

  for(int i = 0; i < 2; i++)
  {
    printf("Veuillez rentrer votre nom: ");
    scanf("%s", joueurs[i].nom);

    printf("Veuillez rentrer votre prenom: ");
    scanf("%s", joueurs[i].prenom);

    printf("Adresse: ");
    scanf("%s", joueurs[i].adresse);

    printf("Age: ");
    scanf("%d", &joueurs[i].age);

    printf("Sexe (0 pour fille, 1 pour garçon): ");
    scanf("%d", &joueurs[i].garcon);
  }

  for(int i = 0; i < 2; i++)
  {
    printf("\nLe joueur %d s'appelle %s %s\n", i+1, joueurs[i].prenom, joueurs[i].nom);
    printf("et habite: %s.\n", joueurs[i].adresse);
    printf("Et c'est un");
    if(joueurs[i].garcon)
      printf(" garçon agé de ");
    else
      printf("e fille agée de ");
    printf("%d ans.\n", joueurs[i].age);
  }

  return 0;
}
