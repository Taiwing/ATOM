#include<stdio.h>
#include<stdlib.h>

void afficheTableau(int *pointeurTableau, int tailleTableau);

int main()
{
  int tableau[4]= {10, 23, 505, 8}; //on peut aussi initialiser le tableau en mettant directement les valeurs entre crochets

  afficheTableau(tableau, 4);

  for(int i = 0; i < 4; i++) //on réutilise la même variable que pour la boucle d'au-dessus, mais elle n'existe que pour le temps de la boucle, donc on la réinitie
    tableau[i] = 0; //on pourrait aussi mettre: "*(tableau + i) = 0"

  afficheTableau(tableau, 4);

  return 0;
}

void afficheTableau(int *pointeurTableau, int tailleTableau) //on aurait peu aussi mettre "int pointeurTableau[]" à la place de "*pointeurTableau"
{
  for(int i = 0; i < tailleTableau; i++)
    printf("valeur de la case %d: %d\n", i+1, *(pointeurTableau + i)); //j'ai le droit de mettre "pointeurTableau[i]" même si le tableau n'a pas été déclaré dans la fonction
}
