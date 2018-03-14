#include<stdio.h>
#include<stdlib.h>
#include "mainV3.h"

int main()
{
  Personne utilisateur;

  printf("Veuillez rentrer votre nom: ");
  scanf("%s", utilisateur.nom);

  printf("Veuillez rentrer votre prenom: ");
  scanf("%s", utilisateur.prenom);

  printf("Vous vous appelez %s %s.\n", utilisateur.prenom, utilisateur.nom);

  return 0;
}
