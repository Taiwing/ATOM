#include<stdio.h>
#include<stdlib.h>
#define COUCOU() printf("Coucou\n"); //avec define, on peut aussi éfinir des constantes qu'on va remplacer par du code source (c'est un macro)

int main()
{
  COUCOU() //ici "COUCOU()" va être remplacé par "printf("Coucou\n");"

  printf("\nLe fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);

  return 0;
}
