#include<stdio.h>
#include<stdlib.h>
//#include "main.h"

int main()
{
  FILE *fichier = NULL; //on crée un pointeur sur notre futur fichier pour récupérer l'output de "fopen"

  fichier = fopen("test.txt", "w"); //la fonction "fopen" (fileopen) permet d'ouvrir un fichier

  if(fichier != NULL) //si le pointeur est différent de 0, autrement dit si l'ouverture a réussi
  {
    fputc('A', fichier); //"fputc" (fileputcharacter) met un caractère dans un fichier ouvert (ici on y met un A)

    fclose(fichier); //"fclose" (fileclose) ferme le fichier, pour qu'il ne prenne plus de place en mémoire
  }
  else
    printf("ERREUR: Impossible d'ouvrir le fichier test.txt\n");

  return 0;
}
