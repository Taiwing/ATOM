#include<stdio.h>
#include<stdlib.h>
#define RACONTER_SA_VIE_DE_CONNARD() printf("Coucou, je m'appelle Connard.\n"); \
printf("J'habite à Paris évidemment,\n"); \
printf("et j'aime rien.\n");

int main()
{
  RACONTER_SA_VIE_DE_CONNARD()

  printf("\nLe fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);

  return 0;
}
