#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fichier = NULL; //on crée un pointeur sur notre futur fichier pour récupérer l'output de "fopen"

  int readFile = 1; //boléen dictant si la boucle continue ou pas à lire le fichier
  int caractere = 0; //stocke le caractère lu

  fichier = fopen("test.txt", "r"); //la fonction "fopen" (fileopen) permet d'ouvrir un fichier ("r" signifie "lecture seule")

  if(fichier != NULL) //si le pointeur est différent de 0, autrement dit si l'ouverture a réussi
  {
    while(readFile)
    {
      caractere = fgetc(fichier); //"fegetc" (filegetcharacter) permet de lire un caractère dans un fichier là où se trouve le "curseur" vituel

      if(caractere == EOF) //si le caractère est le caractère spécial "EOF" (EndOfFile), alors la boucle se termine avec la lecture
      {
        readFile = 0; //on meet "readFile" à 0 pour arrêter la boucle
        printf("\n");
      }
      else
        printf("%c", caractere); //on affiche le caractère lu
    }

    fclose(fichier); //"fclose" (fileclose) ferme le fichier, pour qu'il ne prenne plus de place en mémoire
  }
  else
    printf("ERREUR: Impossible d'ouvrir le fichier test.txt\n");

  return 0;
}
