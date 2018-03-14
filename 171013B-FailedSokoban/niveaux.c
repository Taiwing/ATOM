#include "niveaux.h"

void choixNiveau(SDL_Window* sokoban, int niveau[144])
{
  //on ouvre le fichier de niveaux dont on se servira pour charger le niveau
  FILE *niveaux;
  niveaux = fopen("niveaux.lvl", "r");

  char valeur = '0'; //variable "char" dans laquelle on récupère la valeur donnée par le fichier de niveau

  for(int i = 0; i < 144; i ++) //on exécute la boucle une fois pour chaque case de la grille
  {
    //on récupère la valeur de la case dans le fichier de niveau
    valeur = fgetc(niveaux);

    //on affecte cette valeur à la case du tableau correspondante
    switch(valeur)
    {
      case '0':
        niveau[i] = 0;
        break;
      case '1':
        niveau[i] = 1;
        break;
      case '2':
        niveau[i] = 2;
        break;
      case '3':
        niveau[i] = 3;
        break;
      case '4':
        niveau[i] = 4;
        break;
    }
  }

  fclose(niveaux);
}

void chargerNiveau(SDL_Window* sokoban, int niveau[144])
{
  //on récupère la surface de la fenêtre
  SDL_Surface *surface = SDL_GetWindowSurface(sokoban);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255)); //on remplie la surface de blanc pour effacer le dernier écran

  //on charge les spites nécessaires à la construction du niveau
  SDL_Surface *mur = SDL_LoadBMP("images/mur.bmp");
  SDL_Surface *passage = SDL_CreateRGBSurface(0, 34, 34, 32, 0, 0, 0, 0);
  SDL_FillRect(passage, NULL, SDL_MapRGB(passage->format, 255, 255, 255));
  SDL_Surface *caisse = SDL_LoadBMP("images/caisse.bmp");
  SDL_Surface *objectif = SDL_LoadBMP("images/objectif.bmp");
  SDL_Surface *depart = SDL_LoadBMP("images/mario_bas.bmp");

  //on crée la variable "p" de position
  SDL_Rect p;
  p.x = 0;
  p.y = 0;

  //on lit le tableau "niveau", et on blit l'image en fonction de la valeur lue
  for(int i = 0; i < 144; i++)
  {
    //on switch la valeur de "niveau[i]"
    switch(niveau[i])
    {
      case 0:
        SDL_BlitSurface(mur, NULL, surface, &p);
        break;
      case 1:
        SDL_BlitSurface(passage, NULL, surface, &p);
        break;
      case 2:
        SDL_BlitSurface(caisse, NULL, surface, &p);
        break;
      case 3:
        SDL_BlitSurface(objectif, NULL, surface, &p);
        break;
      case 4:
        SDL_BlitSurface(depart, NULL, surface, &p);
        break;
    }

    //on change les coordonnées pour charger le prochain sprite
    p.x += 34; //on se décale d'une case à droite (34 pixels)

    if(p.x == 408) //si on est arrivé au bout de la ligne
    {
      p.x = 0; //on revient au début de la ligne
      p.y += 34; //on saute une ligne
    }
  }

  //on met à jour la fenêtre
  SDL_UpdateWindowSurface(sokoban);

  //on libère la mémoire
  SDL_FreeSurface(mur);
  SDL_FreeSurface(passage);
  SDL_FreeSurface(caisse);
  SDL_FreeSurface(objectif);
  SDL_FreeSurface(depart);
  SDL_FreeSurface(surface);
}
