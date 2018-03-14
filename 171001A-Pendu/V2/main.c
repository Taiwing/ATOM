#include "main.h"
#include "fonctions.h"

int main()
{
  printf("Bienvenue dans le Pendu !\n");

  printf("\n====REGLES====\n");
  printf("1. En mode Solo, un mot sera choisi aléatoirement par le programme.\n");
  printf("2. En mode Deux Joueurs, l'un des joueurs rentrera le mot mystère (sans accent).\n");
  printf("3. Le programme affichera une suite de '*' symbolisant chacune des lettres du mot.\n");
  printf("4. Vous rentrerez une lettre sans accent (vu que le mot est en majuscules).\n");
  printf("5. Si la lettre est fausse, vous aurez un coup en moins sur 10 (vous perdez à 0).\n");
  printf("6. Si la lettre est bonne, elle s'affichera à la place des '*'.\n");
  printf("7. Vous gagnez si vous devinez le mot mystère.\n");

  int deuxJ = deuxJoueurs();

  do
  {
    partie(deuxJ);
  } while(rejouer());

  return 0;
}
