#include<stdio.h>
#include<stdlib.h>
#include "data.h"

int main()
{
  File* file = initialiser(); //on initialise la file

  enfiler(file, 4);
  enfiler(file, 8);
  enfiler(file, 15);
  enfiler(file, 16);
  enfiler(file, 23);
  enfiler(file, 42);

  printf("Etat de la file:\n");
  afficherFile(file);

  printf("Je défile %d\n", defiler(file));
  printf("Je défile %d\n", defiler(file));

  printf("Etat de la file:\n");
  afficherFile(file);

  return EXIT_SUCCESS;
}
