#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fichier = NULL; //on crée un pointeur sur notre futur fichier pour récupérer l'output de "fopen"

  int age = 0;
  printf("Age ? ");
  scanf("%d", &age);

  fichier = fopen("test.txt", "w"); //la fonction "fopen" (fileopen) permet d'ouvrir un fichier ("w" signifie "écriture seule")

  if(fichier != NULL) //si le pointeur est différent de 0, autrement dit si l'ouverture a réussi
  {
    fprintf(fichier, "L'utilisateur a %d ans.", age); //"fprintf" (fileprintf) fonctionne comme printf, sauf qu'il faut mettre le pointeur de FILE avant

    fclose(fichier); //"fclose" (fileclose) ferme le fichier, pour qu'il ne prenne plus de place en mémoire
  }
  else
    printf("ERREUR: Impossible d'ouvrir le fichier test.txt\n");

  return 0;
}
