#include<stdio.h>
#include<stdlib.h>

void punition(int nombre) //la fonction "punition" ne renvoit aucune valeur, elle est donc de type "void" 
{
  for(int i = 0; i < nombre; i++) //ne pas oublier de préciser le type de variable de "i" dans "for"
    printf("J'ai été très très vilain et je me repens.\n");
}

int main()
{
  int nbRepet = 0;
  printf("Rentrez le nombre de fois que vous avez à écrire la phrase de punition: ");
  scanf("%d", &nbRepet);
  punition(nbRepet);
  return 0;
}
