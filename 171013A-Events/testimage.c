#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#define VITESSE_ZOZOR 5

int main()
{
  SDL_Event event; //on se servira de cette variable plus tard pour gérer les évènements
  int continuer = 1; //boléen dont on se servira pour une boucle "while"

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN); //on crée la fenêtre
  SDL_SetWindowIcon(window, SDL_LoadBMP("sdl_icone.bmp")); //on charge une icone pour la fenêtre
  SDL_Surface *windowSurface = SDL_GetWindowSurface(window); //on obtient la surface de la fenêtre
  SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0)); //on remplit le fond en noir
  SDL_Surface *zozor = SDL_LoadBMP("objectif.bmp"); //on charge "zozor.bmp" dans une surface
  //SDL_SetColorKey(zozor, SDL_TRUE, SDL_MapRGB(zozor->format, 0, 0, 255)); //on choisit quelle couleur sera transparente
  //SDL_SetSurfaceAlphaMod(zozor, 255); //on met la treansparence du reste à 255 (donc opaque)
  //SDL_SetSurfaceBlendMode(zozor, SDL_BLENDMODE_BLEND); //on l'applique
  SDL_Rect pZozor; //on crée la variable de position de "zozor"
  pZozor.x = 800/2 - zozor->w/2; //on le met au milieu
  pZozor.y = 600/2 - zozor->h/2; //on le met au milieu
  SDL_BlitSurface(zozor, NULL, windowSurface, &pZozor); //on charge "zozor" dans la surface de la fenêtre
  SDL_UpdateWindowSurface(window); //on montre les changements à l'écran

  while(continuer) //on va utiliser une boucle infinie de type "while" pour gérer les évènements
  {
    SDL_WaitEvent(&event); //attend qu'un évènement se produise et l'affecte à "event"

    switch(event.type) //on teste le type d'évènements
    {
      case SDL_QUIT: //si l'évènement est de type "Quitter"
        continuer = 0; //alors on met "continuer" à 0 ce qui nous fait sortir de la boucle
        break;
      case SDL_KEYDOWN: //si l'utilisateur appuie sur une touche
        switch(event.key.keysym.sym) //on refait un switch qui accède à la valeur de la touche appuyée
        {
          case SDLK_UP: //si l'utilisateur appuie sur la touche du haut
            pZozor.y -= VITESSE_ZOZOR; //alors on déplace "zozor"
            break;
          case SDLK_DOWN: //si l'utilisateur appuie sur la touche du bas
            pZozor.y += VITESSE_ZOZOR; //alors on déplace "zozor"
            break;
          case SDLK_RIGHT: //si l'utilisateur appuie sur la touche de  droite
            pZozor.x += VITESSE_ZOZOR; //alors on déplace "zozor"
            break;
          case SDLK_LEFT: //si l'utilisateur appuie sur la touche de gauche
            pZozor.x -= VITESSE_ZOZOR; //alors on déplace "zozor"
        }
        break;
    }

    //on remet la surface de la fenêtre en blanc, pour effacer les traces des écrans précédent
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));

    //on effectue les modifications voulues en fonction des évènements
    SDL_BlitSurface(zozor, NULL, windowSurface, &pZozor); //on change par exemple la postion de "zozor à l'écran

    //on affiche le tout à l'écran
    SDL_UpdateWindowSurface(window);
  }

  SDL_FreeSurface(zozor);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
