#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("=== Menu ===\n1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\nVotre Choix ? ");
  char choixMenu = 0, choixValide = 0;
  scanf("%d", &choixMenu); //PUTAIN MAIS ARRETE DE FAIRE CETTE ERREUR N'OUBLIE PAS LE &&&&&&&&&&&&
  choixValide = (0 < choixMenu && choixMenu < 5) ? 1 : 0;
  /*Condition ternaire: Ici la variable "choixValide" est boléenne (elle prend un si elle est vrai,
  et 0 si elle est fausse). Le point d'interrogation est un test de la condition entre parenthèse
  (comme if), si elle est vrai la variable choixValide se verra allouer la valeur directement à droite
  du "?" à savoir 1. Si le test est faux alors la variable prendra la valeur située après ":", qui
  fonctionne donc à la manière d'un "else".*/
  if(choixValide) //Ici "if" teste la variable boléenne choixValide
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
