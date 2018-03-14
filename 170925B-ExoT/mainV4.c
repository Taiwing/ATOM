#include<stdio.h>
#include<stdlib.h>

void afficheTableau(int talbeau[], int tailleTableau);
int sommeTableau(int tableau[], int tailleTableau);
int moyenneTableau(int talbeau[], int tailleTableau);
void copierTableau(int tableau1[], int tailleTableau1, int tableau2[], int tailleTableau2);
void maximumTableau(int tableau[], int tailleTableau, int maximum);

int main()
{
  int tableau[5] = {1, 2, 3, 7, 2};

  afficheTableau(tableau, 5);

  printf("La somme de toutes les case du tableau est: %d\n", sommeTableau(tableau, 5));

  printf("La moyenne des valeurs du tableau est: %d\n", moyenneTableau(tableau, 5));

  int tableau2[6];
  copierTableau(tableau, 5, tableau2, 6);

  afficheTableau(tableau2, 6);

  maximumTableau(tableau2, 6, 2);
  afficheTableau(tableau2, 6);

  return 0;
}

void afficheTableau(int tableau[], int tailleTableau)
{
  for(int i = 0; i < tailleTableau; i++)
    printf("valeur de la case %d: %d\n", i+1, tableau[i]);
}

int sommeTableau(int tableau[], int tailleTableau)
{
  int i, x = 0;

  for(i = 0; i < tailleTableau; i++)
    x += tableau[i];

  return x;
}

int moyenneTableau(int tableau[], int tailleTableau)
{
  return sommeTableau(tableau, tailleTableau)/tailleTableau;
}

void copierTableau(int tableau1[], int tailleTableau1, int tableau2[], int tailleTableau2)
{
  int x = 0;

  if(tailleTableau1 <= tailleTableau2)
    x = tailleTableau1;
  else
    x = tailleTableau2;

  for(int i = 0; i < x; i++)
    tableau2[i] = tableau1[i];
}

void maximumTableau(int tableau[], int tailleTableau, int maximum)
{
  for(int i = 0; i < tailleTableau; i++)
  {
    if(tableau[i] > maximum)
      tableau[i] = 0;
  }
}
