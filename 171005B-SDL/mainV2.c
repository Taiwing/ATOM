#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

void pause();

int main()
{
  if(SDL_Init(SDL_INIT_VIDEO) == -1) //démarrage de la SDL, si erreur:
  {
    fprintf(stderr, "Erreur d'initialisation de la SDL: %s\n", SDL_GetError()); //écriture de l'erreur
    exit(EXIT_FAILURE); //on quitte le programme
  }

  SDL_Window *pWindow = NULL; //remplace SDL_Surface
  pWindow = SDL_CreateWindow("Ma Première fenêtre la putain de ta race.", //titre de la fenêtre
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640, //largeur
                              480, //hauteur
                              SDL_WINDOW_SHOWN); //La fenêtre est visible

  if(pWindow) //si tout s'est bien passé
  {
    //SDL_Delay(15000); //faire une pause de 15s pour voir la fenêtre
    SDL_Renderer *renderer = SDL_CreateRenderer(pWindow, -1, 0); //on crée un rendu de la fenêtre pWindow
    SDL_SetRenderDrawColor(renderer, 104, 34, 139, 255); //on y met la couleur qu'on veut (violet hihihihi)
    SDL_RenderClear(renderer); //affecte les nouvelles valeurs de "Render" au rendu qu'on a créé
    SDL_RenderPresent(renderer); //montre ces nouvelles valeurs à l'utilisateur
    pause(); //met en pause pour qu'on puisse voir la fenêtre
    //SDL_DestroyWindow(pWindow); //DETRUIRE la fenêtre (non mais t'excite pas, ça la ferme et la supprime de la mémoire, c'est tout)
    SDL_Surface *sprite = SDL_CreateRGBSurface(0, 320, 240, 32, 0, 0, 0, 0); //on crée une surface RGB (un sprite)

    if(sprite == NULL) //on vérifie si l'initialisation s'est bien passée
    {
      printf("Erreur de création du sprite: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }

    SDL_FillRect(sprite, NULL, SDL_MapRGB(sprite->format, 238, 118, 0)); //on le colore en orange

    SDL_Rect dest = {640/2 - sprite->w/2, 480/2 - sprite->h/2, 0, 0}; //on crée les coordonnées où on va coller le sprite

    SDL_Surface *pWinSurf = SDL_GetWindowSurface(pWindow); //on crée un pointeur sur la surface de la fenêtre "pWindow"

    if(pWinSurf == NULL) //on vérifie que la fenêtre a bien été récupérée
    {
      printf("Erreur de récupération de la Surface: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }

    SDL_BlitSurface(sprite, NULL, pWinSurf, &dest); //on copie la surface choisie ("sprite") dans la surface de la fenêtre ("pWinSurf")

    SDL_UpdateWindowSurface(pWindow); //on affiche la nouvelle surface à l'écran

    SDL_ShowWindow(pWindow);

    pause();

  }
  else
  {
    fprintf(stderr, "Erreur de la création de la fenêtre: %s\n", SDL_GetError());
  }

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
