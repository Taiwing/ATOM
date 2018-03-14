#include <stdio.h>
#include <stdlib.h>
/*va afficher la suite de BaumSweet de 0 au nombre pris en argument*/

int baumVal(int num);

int main(int argc, char **argv)
{
  if(argc != 2)
    printf("ERROR: wrong number of arguments\n");
  else
  {
    int num = atoi(argv[1]); //valeur entrée par le joueur
    for(int i = 0; i < num+1; i++)
    {
      if(i != 0)
        printf(", ");
      printf("%d", baumVal(i));
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}

int baumVal(int num)
{
  int bit = 0, c = 0;
  while (num > 0 )
  {
    bit = num % 2;
    if(bit == 0)
    {
      c++;
    }
    else if(bit == 1 && (c % 2 == 1)) //si le bit est égal à 1 et que le nombre de 0 est impair
      return 0; //on renvoit 0 pour la suite de BaumSweet car il y a une suite de 0 impaire
    else if(bit == 1 && (c % 2 == 0)) //si le bit est égal à 1 et que le nombre de 0 est pair
      c = 0;
    num /= 2;
  }
  if(c % 2 == 1)
    return 0;
  else
    return 1;
}
