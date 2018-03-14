#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 1000 //taille maximum du tableau

int main()
{
  FILE *fichier = NULL; //on crée un pointeur sur notre futur fichier pour récupérer l'output de "fopen"

  int score[3] = {0}; //on peut initialiser directement toutes les aleurs à 0 d'un coup

  fichier = fopen("test.txt", "r"); //la fonction "fopen" (fileopen) permet d'ouvrir un fichier ("r" signifie "lecture seule")

  if(fichier != NULL) //si le pointeur est différent de 0, autrement dit si l'ouverture a réussi
  {
    fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]); //"fscanf" (filescanf) permet de rentrer des valeurs dans des variables à partir d'un fichier
    printf("Les trois meilleurs scores sont: %d %d et %d\n", score[0], score[1], score[2]);

    fclose(fichier); //"fclose" (fileclose) ferme le fichier, pour qu'il ne prenne plus de place en mémoire
  }
  else
    printf("ERREUR: Impossible d'ouvrir le fichier test.txt\n");

  return 0;
}
