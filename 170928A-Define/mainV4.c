#include<stdio.h>
#include<stdlib.h>
#define MAJEUR(age) if(age >= 18)\
printf("Vous êtes majeur !!!\n");\
else\
{printf("Vous êtes mineur.\n");}

int main()
{
  int ageP = 12;

  MAJEUR(ageP) //on peut donner des variables en paramètres de macros

  printf("\nLe fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);

  return 0;
}
