#include<stdio.h>
#include<stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "zlib.h"
//#include<SDL2/SDL.h>
//#include</usr/local/include/SDL2/SDL_image.h>

void maPause();

int main()
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("Images", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
  SDL_Surface *surface = SDL_GetWindowSurface(window);
  SDL_SetWindowIcon(window, IMG_Load("sdl_icone.bmp"));

  //SDL_Surface *imageFond = SDL_LoadBMP("lac_en_montagne.bmp"); //on charge l'image voulue dans une surface grâce à "SDL_LoadBMP"
  SDL_Surface *imageFond = IMG_Load("lac_en_montagne.bmp");
  SDL_Rect positionFond; //on crée des coordonnées pour la fonctions "SDL_BlitSurface"
  positionFond.x = 0;
  positionFond.y = 0;
  SDL_BlitSurface(imageFond, NULL, surface, &positionFond); //on charge l'image dans la surface de la fenêtre

  IMG_Init(IMG_INIT_PNG);

  SDL_Surface *sapin = IMG_Load("sapin2365.png");
  if(!sapin)
  {
    printf("ERREUR IMG_Load: %s\n", IMG_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_Rect positionSapin;
  positionSapin.x = 500;
  positionSapin.y = 260;
  //SDL_SetColorKey(zozor, SDL_TRUE, SDL_MapRGB(zozor->format, 0, 0, 255)); //ici on rend le pur bleu de l'image transparent
  //SDL_SetSurfaceAlphaMod(zozor, 128); //on règle la transparence alpha de zozor
  //SDL_SetSurfaceBlendMode(zozor, SDL_BLENDMODE_BLEND); //on l'applique
  SDL_BlitSurface(sapin, NULL, surface, &positionSapin);

  SDL_UpdateWindowSurface(window); //on montre les changements à l'écran

  maPause();

  return EXIT_SUCCESS;
}

void maPause()
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
