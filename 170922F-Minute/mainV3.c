#include<stdio.h>
#include<stdlib.h>

void decoupeMinutes(int *pointeurHeures, int *pointeurMinutes);

int main()
{
  int minutes = 0, heures = 0;
  printf("Bienvenue dans Minute, le programme qui découpe un certain nombre de minutes en heures.\n");
  printf("Veuillez rentrer un nombre de minutes: ");
  scanf("%d", &minutes);
  decoupeMinutes(&heures, &minutes); //on donne à la fonction l'adresse des variables "heures" et "minutes", pour ses pointeurs
  printf("Cela fait %d heures et %d minutes.\n", heures, minutes);
  return 0;
}

void decoupeMinutes(int *pointeurHeures, int *pointeurMinutes) //la fontction "decoupeMinutes" va prendre des pointeurs en paramètres
{
  *pointeurHeures = *pointeurMinutes / 60; //ici on modifie directement la valeur de la variable dont l'adresse est stockée dans le pointeur
  *pointeurMinutes %= 60;
}
// PAGE 169 (GIGGITY) AHAHAHAH J'ai chopé la solution du chapitre tout seul KESKE CHUIS INTELLIGENT !!!!
