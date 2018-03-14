#include<stdio.h>
#include<stdlib.h>

int main()
{
  char lettre = 'A'; //on peut affecter un caractère à "char", qui le convertira en nombre via la table ASCII

  printf("%c\n", lettre); //ici printf va afficher le nombre compris dans "lettre" en tant que caractère grâce à la table ASCII

  return 0;
}
