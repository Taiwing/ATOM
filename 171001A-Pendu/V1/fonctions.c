#include "fonctions.h"

char *motAleatoire()
{
  int nbMots = 0, ligneMotMystere = 0;
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

  char *motMystere = malloc((strlen(mot) - 2) * sizeof(char)); //on crée un pointeur sur le mot mystère de taille exactement suffisante au nombre de lettres dans le mot

  for(int i = 0; i < (strlen(mot) - 2); i++)
    motMystere[i] = mot[i];

  fclose(dictionnaire); //on referme le fichier une fois qu'on a fini de l'utiliser

  return motMystere;
}

char lireCaractere()
{
  char caractere = 0;
  caractere = getchar(); //"getchar" (getcharacter) fait rentrer un caractère à l'utilisateur dans la variable "caractere"
  caractere = toupper(caractere); //"toupper" (touppercase) met la lettre en majuscule si elle ne l'est pas
  while(getchar() != '\n'); //ici on a fait une boucle while qui ne contient aucune instructions pour "lire" et ainsi
                            //effacer chaque caractère après le premier rentré par l'utilisateur
  return caractere; //on renvoit finalement le caractere rentré par le joueur
}

int essaiReussi(const char caractere, const char* motMystere)
{
  int reussi = 0, i = 0;

  while(i < strlen(motMystere) && reussi == 0)
    {
      if(motMystere[i] == caractere)
        reussi = 1;

      i++;
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

void partie()
{
  char *motMystere = motAleatoire(); //on choisit aléatoirement le mot mystère via la fonction "motAleatoire"
  int longueurMot = strlen(motMystere), coupRestants = 10;
  motMystere[longueurMot + 1] = '\0'; //juste pour s'assurer que le mot finit bien
  char *motJoueur = malloc(longueurMot * sizeof(char)); //on crée une chaîne de caractère de même taille que le mot mystère
  char caractere = 0;

  for(int i = 0; i < (longueurMot + 1); i++) //on remplie toute la chaîne par des * qui symbolisent les caractères à deviner
  {
    motJoueur[i] = '*';
    if(i == longueurMot)
      motJoueur[i] = '\0';
  }
  
  while(coupRestants > 0)
  {
    printf("\nIl vous reste %d coups à jouer.\n", coupRestants);
    printf("Quel est le mot secret ? %s\n", motJoueur);
    printf("Proposez une lettre: ");

    caractere = lireCaractere(); //"lireCaractere" lit le premier caractère tapé et vide le buffer (les autres caractères dans la mémoire)

    if(essaiReussi(caractere, motMystere)) //on regarde si le joueur a deviné une lettre ou pas
      afficheCarac(caractere, motMystere, motJoueur); //si c'est le cas on affiche les caractères dans "motJoueur"
    else
      coupRestants--; //on retire un coup au joueur s'il n'a pas réussi à deviner

    if(devine(motJoueur)) //si le mot est totalement deviné
    {
      printf("\nGagné ! Le mot secret était bien: %s\n", motMystere); //alors le joueur a gagné
      coupRestants = 0; //on met "coupRestants" à 0 pour sortir de la boucle
    }

    if(coupRestants == 0 && !devine(motJoueur)) //on regarde si le joueur a épuisé son nombre de coups, et n'a pas réussi à deviner
      printf("\nPerdu... Le mot mystère était: %s\n", motMystere); //si c'est le cas, il a perdu
  }

  free(motMystere); //on libère la mémoire qu'on a utilisé pour stocker le mot mystère
  free(motJoueur);
}
