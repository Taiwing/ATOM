#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

void pause();
SDL_Rect creerDest(int i);

int main()
{
  SDL_Init(SDL_INIT_VIDEO); //démarrage de la SDL_Init

  SDL_Window *fDegrade = NULL; //on crée un pointeur vers la fenêtre

  fDegrade = SDL_CreateWindow("Dégradé", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 256, SDL_WINDOW_SHOWN); //on crée la fenêtre

  SDL_Surface *degrade = SDL_GetWindowSurface(fDegrade); //on récupère la surface de "fDegrade" dans un pointeur

  SDL_Surface lignesDegrade[256]; //on crée tableau de type "SDL_Surface" pour les lignes du dégradé

  SDL_Rect dest[256]; //on crée un tableau de type "SDL_Rect" pour les coordonnées

  for(int i = 0; i < 256; i++) //boucle d'initialisation des coordonnées
  {
    dest[i] = creerDest(i); //on attribue une valeur à chaque case du tableau en fonction de i pour la ligne
  }

  for(int i = 0; i < 256; i++)
  {
    lignesDegrade[i] = *SDL_CreateRGBSurface(0, 640, 1, 32, 0, 0, 0, 0); //on crée la surface correspondant à la ligne

    SDL_FillRect(&lignesDegrade[i], NULL, SDL_MapRGB(lignesDegrade->format, i, i, i)); //on remplit chaque ligne par un couleur de plus en plus claire

    SDL_BlitSurface(&lignesDegrade[i], NULL, degrade, &dest[i]); //on place la ligne aux coordonnées voulues dans "degrade"
  }

  SDL_UpdateWindowSurface(fDegrade); //on met à jour la surface de la fenêtre

  pause(); //on laisse le temps à l'utilisateur de voir la fenêtre

  return EXIT_SUCCESS; //Putain de sa mère la pute. J'ai réussi. J'en ai chié pour celui-là.
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

SDL_Rect creerDest(int i)
{
  SDL_Rect dest = {0, i, 0, 0};

  return dest;
}
