#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int saisie(char *chaine, int taille);
void viderBuffer();

int main()
{
  char nom[10];

  printf("Quel est votre nom ?\n");

  saisie(nom, 10);
  printf("Votre nom est %s.\n", nom);
  saisie(nom, 10);
  printf("Votre nom est %s.\n", nom);


  return 0;
}

int saisie(char *chaine, int taille)
{
  char *caractereLu; //pointeur sur le caractère lu par "strchr"

  if(fgets(chaine, taille, stdin) != NULL) //"fgets" peut lire des fichiers, mais peut aussi prendre des caractères directement du clavier avec "stdin" (standardinput)
  {
    caractereLu = strchr(chaine, '\n'); //"strchr" cherche le carctère '\n' dans "chaine", et renvoit un pointeur sur le caractère s'il est trouvé

    if(caractereLu != NULL) //si "strchr" a trouvé le caractère cherché, alors
      *caractereLu = '\0'; //on remplace le caractère '\n' par '\0' dans la chaine
    else
      viderBuffer(); //on vide le buffer vu que qu'il n'y a pas de '\n' dans "chaine"

    return 1;
  }

  return 0; //renvoit une erreur
}

void viderBuffer()
{
  int c = 0;
  while (c != '\n' && c != EOF)
    c = getchar();
}
