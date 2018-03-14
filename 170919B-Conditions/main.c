#include<stdio.h>
#include<stdlib.h>

int main()
{
  int age = 0;
  printf("Veuillez rentrer votre âge: ");
  scanf("%d", &age);
  if(age >= 18)
  {
    printf("Félicitations !! Vous êtes majeur.\n");
  }
  else if(age > 4)
  {
    printf("Aaaaah... La jeunesse...\n");
  }
  else
  {
    printf("Agaaaa Aga Gah gah...\n");
  }
  return 0;
}
