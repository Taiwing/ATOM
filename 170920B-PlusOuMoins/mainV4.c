#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  printf("Bienvenue dans PlusOuMoins ! Le jeu qui vous fait\ndeviner un nombre.\n\n");
  int nbMystere = 0, nbJoueur = 0, nbCoups = 0, continuerPartie = 1, ouiNon = 2, deuxJoueurs = 0, compteur = 0, niveau = 0, erreur = 0, max = 0;
  const int MIN = 1;

  do
  {
    //condition "if" dont les instructions ne sont exécutées que si l'utilisateur n'a pas rentré 1 ou 2
    if(ouiNon < 1 || ouiNon > 2)
      printf("\nERREUR: Veuillez rentrer un choix valide.\n\n");

    printf("Choisissez le mode de jeu:\n1. mode 1 Joueur\n2. mode 2 Joueurs\n");
    scanf("%d", &ouiNon); //le joueur rentre son choix
    deuxJoueurs = (ouiNon == 2) ? 1 : 0;
    //condition ternaire: si l'utilisateur a dit non alors "deuxJoueurs" sera faux, et vrai s'il dit oui
  } while(ouiNon < 1 || ouiNon > 2); //la boucle rejoue si ouiNon ne vaut pas 1 ou 2

  ouiNon = 2; //On remet la valeur par défaut de ouiNon pour que la suite du programme s'exécute normalement

  do
  {
    if(erreur) //s'active s'il y a erreur sur le choix de la difficulté
    {
      printf("\nERREUR: Veuillez rentrer un choix valide.\n\n");
      erreur = 0; //on reset l'erreur
    }

    printf("\nVeuillez maintenant choisir le niveau de difficulté:\n1. entre 1 et 100\n2. entre 1 et 1000\n3. entre 1 et 10000\n");
    scanf("%d", &niveau); //le joueur rentre son choix
    switch(niveau)
    {
      case 1:
        max = 100;
        break;
      case 2:
        max = 1000;
        break;
      case 3:
        max = 10000;
        break;
      default:
        erreur = 1;
        break;
    }
  } while(erreur); //la boucle rejoue si ouiNon ne vaut pas 1 ou 2

  srand(time(NULL));

  //boucle du programme qui se répète si l'utilisateur choisi de refaire une partie
  while(continuerPartie)
  {
    if(ouiNon == 1)
      nbCoups = 0; //on reset le nombre de coups à 0, sinon ils s'additionent parties après parties

    do
    {
      if(deuxJoueurs)
      {
        if(compteur == 0)
        {
          printf("\nDécidez lequel d'entre voux choisira le nombre à deviner.\nMaintenant v");
          compteur++;
        }
        else
        {
          printf("\nV");
        }
        printf("euillez rentrer un nombre entre 1 et %d: ", max);
        scanf("%d", &nbMystere); //PUTAIN JE L'AI ENCORE OUBLIE CET ENCULE

        if((nbMystere < 1 || nbMystere > max) && deuxJoueurs)
        {
          printf("\n\nERREUR: Choix du nombre mystère invalide.\n\n");
        }
      }
    } while((nbMystere < 1 || nbMystere > max) && deuxJoueurs);

    if(!deuxJoueurs)
    {//Génération du nombre aléatoire
      nbMystere = (rand() % max) + MIN; //la formule d'origine était "(rand() % (MAX - MIN + 1)) + MIN", mais elle ici inutile car MIN=1
      printf("\n\n===TIRAGE ALEATOIRE===\n");
    }

    if(deuxJoueurs)
    {
      printf("\n\n====Nombre Mystère sélectionné par le joueur===\n");
    }

    printf("\n");
    //boucle du programme qui se répète tant que le joueur n'a pas trouvé le nombre mystère
    do
    {
      printf("Quel est le nombre ? ");
      scanf("%d", &nbJoueur); //Le joueur rentre le nombre qu'il pense être le bon
      nbCoups++; //on compte le nombre de coups joués

      //dans la conditions "if" on a pas besoin de mettre les "{}" s'il n'y a qu'une seule instruction
      if(nbJoueur < nbMystere)
        printf("C'est plus !\n");
      else if(nbJoueur > nbMystere)
        printf("C'est moins !\n");
      else
        printf("Bravo, vous avez trouvé le nombre mystère en %d coups !!!\n\n", nbCoups);
    } while(nbJoueur != nbMystere);

    //boucle du choix de refaire une partie, qui se répète si le joueur fait une entrée erronée
    do
    {
      //condition "if" dont les instructions ne sont exécutées que si l'utilisateur n'a pas rentré 1 ou 2
      if(ouiNon < 1 || ouiNon > 2)
        printf("\nERREUR: Veuillez rentrer un choix valide.\n\n");

      printf("Voulez-vous faire une autre partie ?\n1. Oui\n2. Non\n");
      scanf("%d", &ouiNon); //le joueur rentre son choix
      continuerPartie = (ouiNon == 1) ? 1 : 0;
      //condition ternaire: si l'utilisateur a dit non alors continuer partie sera faux, et vrai s'il dit oui
    } while(ouiNon < 1 || ouiNon > 2); //la boucle rejoue si ouiNon ne vaut pas 1 ou 2
  }
  return 0;
}
