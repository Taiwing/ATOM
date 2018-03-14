#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("=== Menu ===\n1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\nVotre Choix ? ");
  char choixMenu = 0;
  scanf("%d", &choixMenu); //PUTAIN MAIS ARRETE DE FAIRE CETTE ERREUR N'OUBLIE PAS LE &&&&&&&&&&&&
  if(0 < choixMenu && choixMenu < 5)
  {
    printf("Vous avez choisi le menu ");
    switch(choixMenu)
    {
      case 1:
        printf("Royal Cheese");
        break;
      case 2:
        printf("Mc Deluxe");
        break;
      case 3:
        printf("Mc Bacon");
        break;
      case 4:
        printf("Big Mac");
        break;
    }
    printf("\n");
  }
  else
  {
    printf("\nERREUR: Vous n'avez pas rentré un numéro de menu valide.\n");
    printf("Veuillez relancer le programme et recommencer.\n");
  }
  return 0;
}
