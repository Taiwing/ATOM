#include<stdio.h>
#include<stdlib.h>
#include<string.h> //bibliothèques de fonctions de manipulation des chaînes

int strlenPerso(const char string[]);

int main()
{
  char prenom[100], copiePrenom[100];

  printf("Veuillez rentrer votre prénom: ");

  scanf("%s", prenom);

  printf("Vous vous appelez %s, et il y %d lettres dans votre prénom.\n", prenom, strlenPerso(prenom));
  //strlen calcule la longueur d'un chaîne (stringlength)

  printf("Désormais l'ordinateur va afficher une copie de la chaîne 'prenom': %s\n", strcpy(copiePrenom, prenom));
  //strcpy fait une copie d'un chaîne et la renvoit ensuite via pointeur (stringcopy)

  if(strcmp(prenom, copiePrenom) != 0) //strcmp compare des chaînes, si elles sont identiques, elle reverra 0 (stringcompare)
    printf("Les chaînes 'prenom' et 'copiePrenom' sont différentes désormais.\n");
  else
    printf("Les chaînes 'prenom' et 'copiePrenom' sont toujours les mêmes.\n");

  printf("Désormais l'ordinateur va afficher un version concaténée des deux chaînes du programme: %s\n", strcat(prenom, copiePrenom));
  //strcat fait une concaténation (elle met bout à bout) des chaines de caractères qui lui sont soumises, et renvoit la première modifiée en résultat

  if(strcmp(prenom, copiePrenom) != 0) //strcmp compare des chaînes, si elles sont identiques, elle reverra 0 (stringcompare)
    printf("Les chaînes 'prenom' et 'copiePrenom' sont différentes désormais.\n");
  else
    printf("Les chaînes 'prenom' et 'copiePrenom' sont toujours les mêmes.\n");

  return 0;
}

int strlenPerso(const char string[])
{
  int compteur = 0;

  while(string[compteur] != '\0') //le symbole "\0" signifie la fin de la chaîne, on arrête donc le compteur à la valeur avant celui-ci
    compteur++;

  return compteur; //compteur est ici la longueur de la chaîne de caractère
}
