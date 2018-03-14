#include<stdio.h>
#include<stdlib.h>
#define MAJEUR(age) if(age >= 18)\ //on peut faire des macros qui prennent des parmètres
printf("Vous êtes majeur !!!\n");

int main()
{
  int ageP = 22;

  MAJEUR(ageP) //on peut donner des variables en paramètres de macros

  printf("\nLe fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);

  return 0;
}
