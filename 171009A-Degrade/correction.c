#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

void pause();

int main()
{
  SDL_Init(SDL_INIT_VIDEO); //on initie la bibliothèque

  //on crée notre pointeur de fenêtre
  SDL_Window *window = SDL_CreateWindow("Dégradé MOTHER FUCKAAAAAA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 256, SDL_WINDOW_SHOWN);
  //on crée un pointeur de type "SDL_Surface"
  SDL_Surface *surfaceWindow = SDL_GetWindowSurface(window);

  SDL_Surface ligne[256]; //on crée notre tableau de 256 pointeurs "SDL_Surface" qu'on initie à "NULL"

  SDL_Rect position = {0, 0, 0, 0}; //on crée une varibale de type "SDL_Rect" qu'on réaffectera à chaque fois
  for(int i = 0; i < 256; i ++)

  {
    position.y = i; //on définie la position de la surface en abscisses
    ligne[i] = *SDL_CreateRGBSurface(0, 640, 1, 32, 0, 0, 0, 0); //on crée la surface
    SDL_FillRect(&ligne[i], NULL, SDL_MapRGB(ligne->format, i, i, i)); //on remplit chaque ligne par un couleur de plus en plus claire
    SDL_BlitSurface(&ligne[i], NULL, surfaceWindow, &position); //on colle la ligne dans la surface de la fenêtre
  }

  SDL_UpdateWindowSurface(window); //on montre le résultat à l'écran
  pause(); //on fait une pause le temps de voir ce qu'il se passe

  return EXIT_SUCCESS;
}

void pause()
{
  int continuer = 1;
  SDL_Event event; //crée un ""évènement"

  while(continuer) //tant que continuer = 1
  {
    SDL_WaitEvent(&event); //quand il y a un "évènement"
    switch(event.type) //on vérifie son type
    {
      case SDL_QUIT: //s'il est de type "SDL_Quit", alors on arrête la boucle en mettant "continuer" à 0
        continuer = 0;
    }
  }
}
