#include<stdio.h>
#include<stdlib.h>

int main()
{
  /*
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
  */
  int age = 0, majeur = 0;
  printf("Veuillez rentrer votre âge: ");
  scanf("%d", &age); //NE PAS OUBLIER LE PUTAIN DE SYMBOLE & DANS SCANF
  majeur = age >= 18; //le test "age >= 18" étant vrai, majeur devient égale à 1 Majeur est donc un booléen
  printf("Majeur vaut %d\n", majeur);
  if(majeur) //ici on teste directement la valeur de la variable booléenne "majeur"
  {
    printf("Donc tu es majeur !\n"); //s'affiche si "majeur = 1"
  }
  else
  {
    printf("Donc tu es mineur !\n"); //s'affiche si "majeur = 0"
  }
  return 0;
}
