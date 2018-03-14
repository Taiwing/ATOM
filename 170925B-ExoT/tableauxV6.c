#include<stdio.h>
#include<stdlib.h>

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

void ordonnerTableau(int tableau[], int tailleTableau)
{
  int valMin = 0;
  int coordValMin = 0;
  int valTrans = 0;
  int n = 0;

  while(n < tailleTableau)
  {
    for(int i = n; i < tailleTableau; i++)
    {
      if(tableau[i] < valMin || i == n)
      {
        valMin = tableau[i];
        coordValMin = i;
      }
    }

    while(coordValMin > n)
    {
      valTrans = tableau[coordValMin-1];
      tableau[coordValMin-1] = tableau[coordValMin];
      tableau[coordValMin] = valTrans;
      coordValMin--;
    }

    n++;
  }
}
