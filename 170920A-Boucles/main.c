#include<stdio.h>
#include<stdlib.h>

int main()
{
  int nombreDuDiable = 0;
  /*la boucle "while" exécute les instructions entre
  crochets tant que sa condition est vrai*/
  while(nombreDuDiable != 42)
  {
    printf("Veuillez taper la réponse à la grande question: ");
    scanf("%d", &nombreDuDiable); //BORDEL DE MERDE le &&&&&&&&&&&&&& ABRUTI
  }
  return 0;
}
