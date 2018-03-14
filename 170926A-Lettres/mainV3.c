#include<stdio.h>
#include<stdlib.h>

int main()
{
  char chaine[5];

  for(int i = 0; i < 5; i++)
    scanf("%c", (chaine + i)); //on rentre un carctère dans le tableau "chaine" via l'adresse (tableau + i) qui reverra à chaque case

  for(int i = 0; i < 5; i++)
    printf("%c", chaine[i]); //on affiche le caractère

  printf("\n");
  return 0;
}
