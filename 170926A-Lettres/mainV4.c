#include<stdio.h>
#include<stdlib.h>

int main()
{
  char chaine[6]; //on crée un tableau de 6 pour stocker Y-o-a-n-n + le "\0"

  for(int i = 0; i < 5; i++)
    scanf("%c", (chaine + i)); //on rentre un carctère dans le tableau "chaine" via l'adresse (tableau + i) qui reverra à chaque case

  chaine[5] = '\0'; //'\0' est le symbole de fin de chaîne, cela permet à l'ordinateur de savoir quand la chaîne est terminée

  printf("%s\n", chaine); //"%s" veut dire "string", ou chaîne de caractères

  return 0;
}
