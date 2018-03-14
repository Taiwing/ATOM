#include "menuPrincipal.h"

int menuPrincipal(SDL_Window *sokoban)
{
  //variable qu'on mettre en return
  int choix = 0;

  //on charge l'image du menu
  SDL_Surface *surface = SDL_GetWindowSurface(sokoban);
  SDL_Surface *menu = SDL_LoadBMP("images/menu.bmp");
  SDL_Rect pMenu;
  pMenu.x = 0;
  pMenu.y = 0;
  SDL_BlitSurface(menu, NULL, surface, &pMenu);
  SDL_UpdateWindowSurface(sokoban);

  //menu
  int continuer = 1;
  SDL_Event event;
  while(continuer)
  {
    SDL_WaitEvent(&event); //on attend qu'un évènement se produise et on l'affecte à "event"

    switch(event.type)
    {
      case SDL_QUIT: //si l'utilisateur choisi de fermer la fenêtre
        continuer = 0; //on sort du menu
        choix = 0; //et "menuPrincipal" va renvoyer 0 pour fermer le programme
        break;
      case SDL_KEYDOWN: //si l'utilisateur appuie sur une touche
        switch(event.key.keysym.sym)
        {
          case SDLK_j: //si l'utilisateur tape sur '1'
            continuer = 0;
            choix = 1; //on met "choix" à 1
            break;
          case SDLK_n: //si l'utilisateur tape sur '2'
            continuer = 0;
            choix = 2; //on met "choix" à 2
            break;
        }
        break;
    }
  }

  //on libère la mémoire
  SDL_FreeSurface(surface);
  SDL_FreeSurface(menu);

  return choix;
}
