#include<stdio.h>
#include<stdlib.h>
#include<string.h> //bibliothèques de fonctions de manipulation des chaînes

int strlenPerso(const char string[]);

int main()
{
  char prenom[100];

  printf("Veuillez rentrer votre prénom: ");

  scanf("%s", prenom);

  printf("Vous vous appelez %s, et il y %d lettres dans votre prénom.\n", prenom, strlenPerso(prenom));
  //strlen calcule la longueur d'un chaîne (stringlength)

  return 0;
}

int strlenPerso(const char string[])
{
  int compteur = 0;

  while(string[compteur] != '\0') //le symbole "\0" signifie la fin de la chaîne, on arrête donc le compteur à la valeur avant celui-ci
    compteur++;

  return compteur; //compteur est ici la longueur de la chaîne de caractère
}
