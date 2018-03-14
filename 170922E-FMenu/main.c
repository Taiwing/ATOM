#include<stdio.h>
#include<stdlib.h>

int menu()
{
  int choix = 0;

  while(choix < 1 || choix > 4)
  {
    printf("1. Couilles Sautées sur lit d'andives sugelées\n2. Semence de loutre battue en neige\n3. Kebab\n4. Rectum de poney farci\n");
    scanf("%d", &choix);
    if(choix < 1 || choix > 4)
      printf("\nERREUR: Choix invalide. Veuillez rentrer un nombre correct.\n");
    printf("\n");
  }

  return choix;
}

int main()
{
  printf("Bienvenue dans le fameux restaurant de Maurice Des Gueux.\nVeuillez choisir un plât dans notre menu du jour:\n");
  switch(menu()) //ici switch prend en argument le retour "int" de la fonction "menu"
  {
    case 1:
      printf("Très bon choix, je vois que monsieur est un couillaisseur.\n");
      break;
    case 2:
      printf("Un met très fin... Je vous apporte votre bol de sperme tout de suite.\n");
      break;
    case 3:
      printf("Ok. Salade Tomate Oignons je présume ?\n");
      break;
    case 4:
      printf("Ahh apparemment monsieur a très faim. Qu'on lui donne du cul tout de suite !\n");
      break;
  }
  return 0;
}
