#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  printf("Bienvenue dans PlusOuMoins ! Le jeu où vous devez deviner\nquel nombre, compris entre 1 et 100, a été tiré par l'ordinateur.\n\n");
  int nbMystere = 0, nbJoueur = 0;
  const int MAX = 100, MIN = 1;

  //Génération du nombre aléatoire
  srand(time(NULL));
  nbMystere = (rand() % MAX) + MIN; //la formule d'origine était "(rand() % (MAX - MIN + 1)) + MIN", mais elle ici inutile car MIN=1

  //boucle du programme qui se répète tant que le joueur n'a pas trouvé le nombre mystère
  do
  {
      printf("Quel est le nombre ? ");
      scanf("%d", &nbJoueur);
      if(nbJoueur < nbMystere)
      {
        printf("C'est plus !\n");
      }
      else if(nbJoueur > nbMystere)
      {
        printf("C'est moins !\n");
      }
  } while(nbJoueur != nbMystere);

  //phrase de félicitation quand le joueur a finalement deviné
  printf("Bravo, vous avez trouvé le nombre mystère !!!\n");
  return 0;
}
