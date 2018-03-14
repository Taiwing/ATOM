#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int saisie(char *chaine, int taille);
void viderBuffer();
long saisirLong();
double saisirDouble();

int main()
{
  char nom[10];
  long age = 0;
  const double C = 2.99792458;
  double essai = 0;

  printf("Quel est votre nom ?\n");

  if(saisie(nom, 10)) //saisie retourne un boléen, donc si tout se passe bien, on exécute l'instruction suivante
    printf("Votre nom est %s.\n", nom);
  else
    printf("\nERREUR: saisie incorrecte\n");

  printf("Quel âge avez-vous ?\n");
  age = saisirLong();
  printf("Vous avez %d ans.\n", age);

  printf("Vitesse de la lumière en 10^8 m/s: ");
  essai = saisirDouble();

  if(essai == C)
    printf("Bien joué ! La vitesse de la lumière dans le vide est effectivement de %f x 10^8 m/s.\n", essai);
  else
    printf("Raté. La réponse était %f x 10^8 m/s, pas %f\n", C, essai);

  return 0;
}

int saisie(char *chaine, int taille)
{
  char *caractereLu; //pointeur sur le caractère lu par "strchr"

  if(fgets(chaine, taille, stdin) != NULL) //"fgets" peut lire des fichiers, mais peut aussi prendre des caractères directement du clavier avec "stdin" (standardinput)
  {
    caractereLu = strchr(chaine, '\n'); //"strchr" cherche le carctère '\n' dans "chaine", et renvoit un pointeur sur le caractère s'il est trouvé

    if(caractereLu != NULL) //si "strchr" a trouvé le caractère cherché, alors
    {
      *caractereLu = '\0'; //on remplace le caractère '\n' par '\0' dans la chaine
      return 1; //tout s'est bien passé
    }
  }
  //on vide le buffer vu que qu'il n'y a pas de '\n' dans "chaine" (la chaîne était trop longue, on effece les caractères restants)
  viderBuffer(); //on vide aussi le buffer s'il y a eu un problème majeur lors de "fgets"
  return 0; //renvoit une erreur
}

void viderBuffer() //vider le buffer signifie vider de la mémoire les cractères tapés au clavier
{
  int c = 0;
  while (c != '\n' && c != EOF)
    c = getchar();
}

long saisirLong()
{
  long nombre = 0;
  char nombreTexte[100] = {0};

  if(saisie(nombreTexte, 100)) //si tout se passe bien
  {
        nombre = strtol(nombreTexte, NULL, 10); //"strtol" (stringtolong) convertie une chaîne en long, donc "nombre" sera égal au nombre qu'à rentré l'utilisateur
  }

  return nombre; //on renvoit le nombre
}

double saisirDouble()
{
  double nombre = 0;
  char *virgule = NULL;
  char nombreTexte[100] = {0};

  if(saisie(nombreTexte, 100)) //si tout se passe bien
  {
    virgule = strchr(nombreTexte, ','); //on cherche une virgule dans "nombreTexte"

    if(virgule != NULL) //s'il y en a une
      *virgule = '.'; //on la remplace par un point pour que ça passe dans "strtod"

    nombre = strtod(nombreTexte, NULL); //"strtod" (stringtodouble) convertie une chaîne en double, donc "nombre" sera égal au nombre qu'à rentré l'utilisateur
  }

  return nombre; //on renvoit le nombre
}
