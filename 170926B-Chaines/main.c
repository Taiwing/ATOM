#include<stdio.h>
#include<stdlib.h>
#include<string.h> //bibliothèques de fonctions de manipulation des chaînes

int main()
{
  char prenom[100];

  printf("Veuillez rentrer votre prénom: ");

  scanf("%s", prenom);

  printf("Vous vous appelez %s, et il y %d lettres dans votre prénom.\n", prenom, strlen(prenom));
  //strlen calcule la longueur d'un chaîne (stringlength)

  return 0;
}
