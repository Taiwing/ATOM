#include <stdio.h>
#include <stdlib.h>

int main()
{
  int vitesse = 0;
  int niveau = 1;
  while(vitesse != 1)
  {
    niveau++;
    vitesse = (0.8-((niveau)*0.025)) * 60;
    printf("NIVEAU %d: vitesse %d\n", niveau, vitesse);
  }
}
