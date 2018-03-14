#include<stdio.h>
#include<stdlib.h>

int main()
{
  const int NOMBRE_DE_VIES_INITIALES = 5; /*ici on déclare une constante
  en MAJUSCULE pour mieux les reconnaître dans le code*/
  int nombreDeVies = NOMBRE_DE_VIES_INITIALES; /*on donne la valeur de 
  NOMBRE_DE_VIES_INITIALES à nombreDeVies, qui sera donc 5*/
  nombreDeVies = 4; //change la valeur de nombreDeVies à 4
  nombreDeVies = 3;
  return 0;
}
