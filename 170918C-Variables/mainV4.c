#include<stdio.h>
#include<stdlib.h>

int main()
{
  const int NOMBRE_DE_VIES_INITIALES = 5; /*ici on déclare une constante
  en MAJUSCULE pour mieux les reconnaître dans le code*/
  printf("valeur de la constante NOMBRE_DE_VIES_INITIALES: %d\n", NOMBRE_DE_VIES_INITIALES); /*affiche la valeur de la constante
  NOMBRE_DE_VIES_INITIALES grâce au symbole %d qui permet d'afficher un nombre entier à partir d'une variable ou constante*/
  int nombreDeVies = NOMBRE_DE_VIES_INITIALES; /*on donne la valeur de
  NOMBRE_DE_VIES_INITIALES à nombreDeVies, qui sera donc 5*/
  printf("valeur de la variable nombreDeVies après initialisation: %d\n", nombreDeVies); //affiche la valeur de nombreDeVies
  nombreDeVies = 4; //change la valeur de nombreDeVies à 4
  nombreDeVies = 3;
  printf("valeur de nombreDeVies après que le joueur se soit pris deux coups sur la gueule: %d\n", nombreDeVies);
  return 0;
}
