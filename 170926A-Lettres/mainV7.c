#include<stdio.h>
#include<stdlib.h>

int main()
{
  char prenom[100]; //on met 100 pour pouvoir stocker n'importe quel prénom

  printf("Programme de réupération de prénom.\nVeuillez rentrer votre prénom: ");

  scanf("%s", prenom);

  printf("Vous vous appelez %s.\n", prenom);

  return 0;
}
