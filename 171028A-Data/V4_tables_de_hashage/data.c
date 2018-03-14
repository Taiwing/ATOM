#include<stdio.h>
#include<stdlib.h>
#include "data.h"

int hashage(char *chaine)
{
  int hash = 0; //valeur qu'on renverra
  
  for(int i = 0; chaine[i] != '\0'; i++) //tant qu'il reste des caractères à lire
  {
    hash+= chaine[i]; //on ajoute la valeur numérique du caractère au "hash"
  }

  hash %= 100; //on fait un "%100" pour que sa valeur soit comprise entre 0 et 99

  return hash; //on retourne la valeur obtenue
}
