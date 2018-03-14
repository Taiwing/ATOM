#include<stdio.h>
#include<stdlib.h>

int main()
{
  //char chaine[] = "Yoann"; //on peut initialiser un tableau "char" en écrivant directement la chaîne (le symbole "\0" sera automatiquemnt ajouté)
  char* chaine = "Yoann"; //revient au même que l'écriture du dessus

  printf("%s\n", chaine); //"%s" veut dire "string", ou chaîne de caractères

  return 0;
}
