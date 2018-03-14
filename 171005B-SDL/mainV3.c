#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

void pause();

int main()
{
  SDL_Init(SDL_INIT_VIDEO); //démarrage de la SDL

  SDL_Window *pWindow = NULL; //on crée un pointeur vers la fenêtre

  //on crée la fenêtre
  pWindow = SDL_CreateWindow("Ma Première fenêtre la putain de ta race.", //titre de la fenêtre
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640, //largeur
                              480, //hauteur
                              SDL_WINDOW_SHOWN); //La fenêtre est visible

  SDL_Surface *pWinSurf = SDL_GetWindowSurface(pWindow); //on crée un pointeur sur la surface de la fenêtre "pWindow"

  SDL_FillRect(pWinSurf, NULL, SDL_MapRGB(pWinSurf->format, 104, 34, 139)); //on remplie la surface de la fenêtre de violet

  SDL_UpdateWindowSurface(pWindow); //on affiche la surface modifiée à l'écran

  pause(); //met en pause pour qu'on puisse voir la fenêtre

  SDL_Surface *sprite = SDL_CreateRGBSurface(0, 320, 240, 32, 0, 0, 0, 0); //on crée une surface RGB (un sprite)

  SDL_FillRect(sprite, NULL, SDL_MapRGB(sprite->format, 238, 118, 0)); //on le colore en orange

  SDL_Rect dest = {640/2 - sprite->w/2, 480/2 - sprite->h/2, 0, 0}; //on crée les coordonnées où on va coller le sprite

  SDL_BlitSurface(sprite, NULL, pWinSurf, &dest); //on copie la surface choisie ("sprite") dans la surface de la fenêtre ("pWinSurf")

  SDL_UpdateWindowSurface(pWindow); //on affiche la nouvelle surface à l'écran

  SDL_ShowWindow(pWindow); //on montre la fenêtre à l'écran

  pause();

  SDL_Quit(); //Arrêt de la SDL (Libération de la mémoire)

  return EXIT_SUCCESS; //EXIT_SUCCES et EXIT_FAILURE sont des constantes de stdlib.h
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
