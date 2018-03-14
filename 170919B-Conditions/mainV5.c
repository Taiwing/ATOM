#include<stdio.h>
#include<stdlib.h>

int main()
{
  int age = 0;
  printf("Veuillez rentrer votre âge: ");
  scanf("%d", &age);
  switch(age) //remplace "if" dans certains cas
  {
    case 1: //pour "age == 1"
      printf("Agaaaaaaagaga Gueu Gah...\n");
      break; //permet à l'ordinateur de sortir des acolades de switch quand il a fini de lire les instructions
    case 3:
      printf("Wow, alors on va rentrer à l'école maternelle hein ?\n");
      break;
    case 6:
      printf("Maintenant c'est l'école primaire... Bien joué !\n");
      break;
    case 15:
      printf("Ahhh l'âge bête... Je m'en souviens comme si c'était hier.\n");
      break;
    case 57:
      printf("Bientôt la maison de retraite alors ?\n");
      break;
    case 68:
      printf("Salut papy !\n");
      break;
    default: // remplace "else"
      printf("Je n'ai aucune phrase de prête pour ton âge\n");
      break;
  }
  return 0;
}
