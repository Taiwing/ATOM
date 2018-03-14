#include "main.h"
#include "fonctions.h"

int main()
{
  printf("Bienvenue dans le Pendu !\n");

  printf("\n====REGLES====\n");
  printf("1. Un mot sera choisi aléatoirement par le programme à partir du dictionnaire.\n");
  printf("2. Le programme affichera une suite de '*' symbolisant chacune des lettres du mot.\n");
  printf("3. Vous rentrerez une lettre sans accent (vu que le mot est en majuscules).\n");
  printf("4. Si la lettre est fausse, vous aurez un coup en moins sur 10 (vous perdez à 0).\n");
  printf("5. Si la lettre est bonne, elle s'affichera à la place des '*'.\n");
  printf("6. Vous gagnez si vous devinez le mot mystère.\n");

  partie();

  return 0;
}
