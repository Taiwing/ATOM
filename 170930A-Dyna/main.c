#include<stdio.h>
#include<stdlib.h>

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
  int x;
  int y;
};

int main()
{
  printf("char: %d octets\n", sizeof(char)); //"sizeof" permet de savoir combien d'octets de mémoire prend un certain type de variable
  printf("int: %d octets\n", sizeof(int));
  printf("long: %d octets\n", sizeof(long));
  printf("double: %d octets\n", sizeof(double));
  printf("Structure 'Coordonnees': %d octets\n", sizeof(Coordonnees));

  return 0;
}
