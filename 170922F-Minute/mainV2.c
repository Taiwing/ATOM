#include<stdio.h>
#include<stdlib.h>

void decoupeMinutes(int minutesD);
int minutes = 0, heures = 0; //test: on fait de minutes et heures des variables globales pour que decoupeMinutes puisse y accéder

int main()
{
  //int minutes = 0, heures = 0;
  int *monPointeur = NULL; //on initie un pointeur en rajoutant le symbole "*" devant le nom (NULL ici est l'équivalent de 0 pour les pointeurs)
  int *pointeurMinutes = &minutes; //on crée un autre pointeur qu'on initie avec l'adresse de la variable "minutes" grâce au symbole "&"
  printf("Bienvenue dans Minute, le programme qui découpe un certain nombre de minutes en heures.\n");
  printf("Veuillez rentrer un nombre de minutes: ");
  scanf("%d", &minutes);
  decoupeMinutes(minutes);
  printf("Cela fait %d heures et %d minutes.\n", heures, *pointeurMinutes); // avec le symbole "*" on affiche la valeur de la variable dont l'adresse est stockée dans ce pointeur
  printf("Pendant qu'on y est l'adresse en héxadécimal de la variable minutes est: %p\n", pointeurMinutes); //le nom du pointeur seul renvoit l'adresse enregistrée
  printf("Sachant qu'en décimal ça nous fait: %d\n", pointeurMinutes);
  return 0;
}

void decoupeMinutes(int minutesD)
{
  heures = minutesD / 60;
  minutes = minutesD % 60;
}
// PAGE 169 (GIGGITY)
