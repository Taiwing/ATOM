#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 1000 //taille maximum du tableau

int main()
{
  FILE *fichier = NULL; //on crée un pointeur sur notre futur fichier pour récupérer l'output de "fopen"

  char chaineLue[TAILLE_MAX] = ""; //chaine vide

  fichier = fopen("test.txt", "r"); //la fonction "fopen" (fileopen) permet d'ouvrir un fichier ("r" signifie "lecture seule")

  if(fichier != NULL) //si le pointeur est différent de 0, autrement dit si l'ouverture a réussi
  {
    while(fgets(chaineLue, TAILLE_MAX, fichier) != NULL) //"fgets" (filegetstring) permet de lire une chaîne de caractère dans un fichier
        printf("%s", chaineLue);

    fclose(fichier); //"fclose" (fileclose) ferme le fichier, pour qu'il ne prenne plus de place en mémoire
  }
  else
    printf("ERREUR: Impossible d'ouvrir le fichier test.txt\n");

  return 0;
}
