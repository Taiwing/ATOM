#include<stdio.h>
#include<stdlib.h>

void saisie(char *chaine, int taille);

int main()
{
  char nom[10];

  printf("Quel est votre nom ?\n");


  saisie(nom, 10);
  printf("Votre nom est %s.\n", nom);

  return 0;
}

void saisie(char *chaine, int taille)
{
  fgets(chaine, taille, stdin); //"fgets" peut lire des fichiers, mais peut aussi prendre des caractères directement du clavier avec "stdin" (standardinput)
  for(int i = 0; i < taille; i++)
  {
    if(chaine[i] == '\n')
      chaine[i] = '\0';
  }
}
