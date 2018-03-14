#include<stdio.h>
#include<stdlib.h>

int fois3(int nombre) //on crée la fonction "fois3" pour multiplier un nombre par 3 qu'on place en dehors de "main"
{
  return nombre * 3; //la fonction revoit la nouvelle valeur de nombre en sortie
}

int main()
{
  int nbUser = 0;

  printf("Veuillez rentrer un nombre à multiplier par 3: ");
  scanf("%d", &nbUser); //l'utilisateur rentre le nombre qu'il veut multiplier par 3

  printf("%d * 3 = %d\n", nbUser, fois3(nbUser));
  //on a pas besoin de créer une variale pour le retour de la fonction "fois3", on peut directement l'appeler dans "printf"

  return 0;
}
