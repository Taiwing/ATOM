#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("Bienvenue dans ma Calculatrice.\nVeuillez tout d'abord choisir deux nombres entiers.\n");
  printf("Les cinq opérations informatiques de base leur seront ensuite appliqués.\n\n");
  int nombre1 = 0, nombre2 = 0, resultat = 0;
  printf("Veuillez rentrer le premier nombre: ");
  scanf("%d", &nombre1); // L'utilisateur rentre la valeur du premier nombre1
  printf("Veuillez maintenant rentrer le deuxième nombre: ");
  scanf("%d", &nombre2);
  resultat = nombre1 + nombre2;
  printf("\n%d + %d = %d\n", nombre1, nombre2, resultat);
  resultat = nombre1 - nombre2;
  printf("%d - %d = %d\n", nombre1, nombre2, resultat);
  resultat = nombre1 * nombre2;
  printf("%d * %d = %d\n", nombre1, nombre2, resultat);
  resultat = nombre1 / nombre2;
  printf("%d / %d = %d\n", nombre1, nombre2, resultat);
  resultat = nombre1 % nombre2;
  printf("%d %% %d = %d\n", nombre1, nombre2, resultat);
  return 0;
}
