#include<stdio.h>
#include<stdlib.h>
#include "data.h"

int main()
{
  Liste *liste = initialisation(); //on crée une liste
  insertion(liste, 0, 3); //on ajoute '3' au début de celle-ci
  insertion(liste, 1, 4); //on ajoute '4' en deuxième position
  supression(liste, 0); //puis on le supprime
  insertion(liste, 2, 5); //on ajoute '5' en troisième position
  insertion(liste, 3, 6); //on ajoute '6' en quatrième position
  insertion(liste, 2, 7); //on ajoute '7' en troisième position
  insertion(liste, 5, 9); //on ajoute '9' en sixième position
  afficherListe(liste);

  supression(liste, 0);
  afficherListe(liste);

  insertion(liste, 0, 4);
  afficherListe(liste);

  supression(liste, 1);
  afficherListe(liste);

  insertion(liste, 1, 0);
  afficherListe(liste);

  supression(liste, 2);
  afficherListe(liste);

  insertion(liste, 2, 7);
  afficherListe(liste);

  supression(liste, 3);
  afficherListe(liste);

  insertion(liste, 3, 5);
  afficherListe(liste);

  supression(liste, 4);
  afficherListe(liste);

  insertion(liste, 4, 6);
  afficherListe(liste);

  supression(liste, 5);
  afficherListe(liste);

  insertion(liste, 5, 9);
  afficherListe(liste);

  detruireListe(liste);

  return EXIT_SUCCESS;
}
