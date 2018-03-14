#include "fonctions.h"

char *motAleatoire()
{
  int nbMots = 0, ligneMotMystere = 0, l = 0;
  char mot[TAILLE_MAX];

  FILE *dictionnaire = NULL; //on crée le pointeur vers le fichier
  dictionnaire = fopen("liste_francais.txt", "r"); //on ouvre le fichier dictionnaire d'où on tiendra notre mot

  if(dictionnaire == NULL) //si l'ouverture échoue, on arrête le programme
    exit(0);

  while(fgets(mot, TAILLE_MAX, dictionnaire) != NULL)
  {
    nbMots++; //on compte le nombre de mots correspondant à la taille maximum déterminée à l'avance
  }

  //Sélection aléatoire de la ligne et donc du mot mystère
  srand(time(NULL));
  ligneMotMystere = (rand() % nbMots) + 1;

  rewind(dictionnaire); //on revient au début du dictionnaire

  for(int i = 0; i < ligneMotMystere; i++) //on lit le dictionnaire jusqu'à la ligne choisie aléatoirement
  {
    fgets(mot, TAILLE_MAX, dictionnaire);
  }

  l = strlen(mot);

  mot[(l - 2)] = '\0';

  char *motMystere = malloc(((l - 2) * sizeof(char))); //on crée un pointeur sur le mot mystère de taille exactement suffisante au nombre de lettres dans le mot plus le caractère '\0'

  for(int i = 0; i < (l - 2); i++)
    motMystere[i] = mot[i];

  motMystere[(l - 2)] = '\0'; //on met déjà le '\0' pour bloquer la chaîne

  fclose(dictionnaire); //on referme le fichier une fois qu'on a fini de l'utiliser

  printf("\nLe motMystere est %s et fait %d caractères.\n", motMystere, strlen(motMystere)); //autre ligne de test

  return motMystere;
}

char *motChoisi()
{
  char mot[TAILLE_MAX];
  printf("Veuillez rentrer le mot mystère: ");
  scanf("%s", mot);
  int l = strlen(mot);

  for(int i = 0; i < l; i++)
  {
    mot[i] = toupper(mot[i]); //on met les caracactères en majuscules
  }

  char *motMystere = malloc((l + 1) * sizeof(char));

  for(int i = 0; i < (l + 1); i++)
  {
    motMystere[i] = mot[i];
  }

  motMystere[(l + 1)] = '\0';
  while(getchar() != '\n');
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //pour faire disparaître le mot choisi par le premier joueur
  return motMystere;
}

char lireCaractere()
{
  char caractereF = '0';
  caractereF = getchar(); //"getchar" (getcharacter) fait rentrer un caractère à l'utilisateur dans la variable "caractere"
  caractereF = toupper(caractereF); //"toupper" (touppercase) met la lettre en majuscule si elle ne l'est pas
  while(getchar() != '\n'); //ici on a fait une boucle while qui ne contient aucune instructions pour "lire" et ainsi
                            //effacer chaque caractère après le premier rentré par l'utilisateur
  return caractereF; //on renvoit finalement le caractere rentré par le joueur
}

int essaiReussi(const char caractere, const char* motMystere)
{
  int reussi = 0;

  for(int i = 0; i < strlen(motMystere); i ++)
    {
      if(motMystere[i] == caractere)
      {
        reussi = 1;
        i = 345;
      }
    }

  return reussi;
}

void afficheCarac(const char caractere, const char* motMystere, char* motJoueur)
{
  for(int i = 0; i < strlen(motMystere); i++)
  {
    if(motMystere[i] == caractere)
      motJoueur[i] = caractere;
  }
}

int devine(const char* motJoueur)
{
  int motDevine = 1;
  int longueur = strlen(motJoueur);

  for(int i = 0; i < longueur; i++)
    if(motJoueur[i] == '*')
    {
      motDevine = 0;
      i = longueur;
    }

  return motDevine;
}

void partie(int deuxJ)
{
  char *motMystere = NULL;

  if(deuxJ) //si le joueur a choisi le mode deux joueurs
    motMystere = motChoisi(); //l'un des joueurs rentre un mot
  else //mode solo
    motMystere = motAleatoire(); //on choisit aléatoirement le mot mystère via la fonction "motAleatoire"

  int longueurMot = strlen(motMystere), coupsRestants = 10;
  char *motJoueur = malloc(longueurMot * sizeof(char)); //on crée une chaîne de caractère de même taille que le mot mystère
  char caractere = 0;

  for(int i = 0; i < (longueurMot + 1); i++) //on remplie toute la chaîne par des * qui symbolisent les caractères à deviner
  {
    motJoueur[i] = '*';
    if(i == longueurMot)
      motJoueur[i] = '\0';
  }

  while(coupsRestants > 0)
  {
    affichePendu(coupsRestants);

    printf("\nIl vous reste %d coups à jouer.\n", coupsRestants);
    printf("Quel est le mot secret ? %s\n", motJoueur);
    printf("Proposez une lettre: ");

    caractere = lireCaractere(); //"lireCaractere" lit le premier caractère tapé et vide le buffer (les autres caractères dans la mémoire)

    if(essaiReussi(caractere, motMystere)) //on regarde si le joueur a deviné une lettre ou pas
      afficheCarac(caractere, motMystere, motJoueur); //si c'est le cas on affiche les caractères dans "motJoueur"
    else
      coupsRestants--; //on retire un coup au joueur s'il n'a pas réussi à deviner

    if(devine(motJoueur)) //si le mot est totalement deviné
    {
      printf("\nGagné ! Le mot secret était bien: %s\n", motMystere); //alors le joueur a gagné
      coupsRestants = 0; //on met "coupsRestants" à 0 pour sortir de la boucle
    }

    if(coupsRestants == 0 && !devine(motJoueur)) //on regarde si le joueur a épuisé son nombre de coups, et n'a pas réussi à deviner
    {
      affichePendu(coupsRestants);
      printf("\nPerdu... Le mot mystère était: %s\n", motMystere); //si c'est le cas, il a perdu
    }
  }

  free(motMystere); //on libère la mémoire qu'on a utilisé pour stocker le mot mystère
  free(motJoueur);
}

int rejouer()
{
  char choix = '0';
  printf("\nVoulez vous rejouer ?\n1.Oui\n2.Non\n");
  choix = getchar(); //on récupère le caractère tapé dans "reponse"
  while(getchar() != '\n'); //on vide le buffer ici également (raison probable du bug casse-couille)

  if(choix == '1') //si le joueur rentre un '1' alors "rejouer" est vraie
    return 1;
  else //toute autre entrée fera que "rejouer" sera fausse
    return 0;
}

int deuxJoueurs()
{
  int erreur;
  char choixJ = '0';

  do
  {
    erreur = 0;
    printf("\nMode de jeu:\n1.Solo\n2.Deux Joueurs\n");
    choixJ = getchar();
    while(getchar() != '\n');

    if(choixJ == '1')
      return 0;
    else if(choixJ == '2')
      return 1;
    else
    {
      printf("\n\nERREUR: veuillez renter un choix valide.\n");
      erreur = 1;
    }
  } while(erreur == 1);
}
