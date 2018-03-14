#include<stdio.h>
#include<stdlib.h>

void decoupeMinutes(int minutesD);
int minutes = 0, heures = 0; //test: on fait de minutes et heures des variables globales pour que decoupeMinutes puisse y accéder

int main()
{
  //int minutes = 0, heures = 0;
  printf("Bienvenue dans Minute, le programme qui découpe un certain nombre de minutes en heures.\n");
  printf("Veuillez rentrer un nombre de minutes: ");
  scanf("%d", &minutes);
  decoupeMinutes(minutes);
  printf("Cela fait %d heures et %d minutes.\n", heures, minutes);
  return 0;
}

void decoupeMinutes(int minutesD)
{
  heures = minutesD / 60;
  minutes = minutesD % 60;
}
