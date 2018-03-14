#include<stdio.h>
#include<stdlib.h>

int main()
{
  int age = 0, argent = 0;

  printf("Veuillez rentrer votre âge: ");
  scanf("%d", &age);
  if(age >= 18)
  {
    if(age == 18) // "==" teste l'égalité à ne pas confondre avec "=" qui modifie l'égalité
    {
      printf("Ahh... Vous venez de devenir majeur.\n");
    }
    else
    {
      printf("Félicitations !! Vous êtes majeur.\n");
    }
  }
  else if(age > 4)
  {
    printf("Aaaaah... La jeunesse...\n");
  }
  else
  {
    printf("Agaaaa Aga Gah gah...\n");
  }

  printf("Veuillez maintenant nous dire la somme d'argent que vous voulez déposer: ");
  scanf("%d", &argent);
  if(age > 30 || argent >= 100000) //le symbole || signifie "OU" dans une condition
  {
    printf("Bienvenue à la PicsousBanque !\n");
  }
  else
  {
    printf("Désolé, non seulement vous êtres trop jeune, mais en plus\n");
    printf("vous n'avez pas assez de liquidités pour ouvrir un compte.\n");
  }
  return 0;
}
