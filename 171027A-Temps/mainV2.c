#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#define VITESSE_ZOZOR 34

Uint32 bougerZozor(Uint32 intervalle, void *parametre);

int main()
{
  SDL_Event event; //on se servira de cette variable plus tard pour gérer les évènements
  int continuer = 1; //boléen dont on se servira pour une boucle "while"
  int tempsPrecedent = 0, tempsActuel = 0; //ces variables vont nous servir à déplacer zozor à intervals réguliers
  int deplacement = 1; //variable boléenne pour activer/desactiver le déplacement de zozor
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER); //on appelle la fonction vidéo pour la fenêtre et le timer

  SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN); //on crée la fenêtre
  SDL_SetWindowIcon(window, SDL_LoadBMP("sdl_icone.bmp")); //on charge une icone pour la fenêtre
  SDL_Surface *windowSurface = SDL_GetWindowSurface(window); //on obtient la surface de la fenêtre
  SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 255, 255, 255)); //on remplit le fond en blanc
  SDL_Surface *zozor = SDL_LoadBMP("zozor.bmp"); //on charge "zozor.bmp" dans une surface
  SDL_SetColorKey(zozor, SDL_TRUE, SDL_MapRGB(zozor->format, 0, 0, 255)); //on choisit quelle couleur sera transparente
  SDL_SetSurfaceAlphaMod(zozor, 255); //on met la treansparence du reste à 255 (donc opaque)
  SDL_SetSurfaceBlendMode(zozor, SDL_BLENDMODE_BLEND); //on l'applique
  SDL_Rect pZozor; //on crée la variable de position de "zozor"
  pZozor.x = 800/2 - 84/2; //on le met au milieu
  pZozor.y = 600/2 - 96/2; //on le met au milieu
  SDL_BlitSurface(zozor, NULL, windowSurface, &pZozor); //on charge "zozor" dans la surface de la fenêtre
  SDL_UpdateWindowSurface(window); //on montre les changements à l'écran

  SDL_TimerID timer;

  while(continuer) //on va utiliser une boucle infinie de type "while" pour gérer les évènements
  {
    SDL_PollEvent(&event); //si un évènement se produit il est affecté à "event"

    switch(event.type) //on teste le type d'évènements
    {
      case SDL_QUIT: //si l'évènement est de type "Quitter"
        continuer = 0; //alors on met "continuer" à 0 ce qui nous fait sortir de la boucle
        break;
      case SDL_KEYDOWN: //si l'utilisateur appuie sur une touche
        if(event.key.keysym.sym == SDLK_p) //touche 'p'
        {
          if(deplacement) //si zozor se déplace
            deplacement = 0; //alors on l'arrête
          else //sinon
            deplacement = 1; //on le déplace
        }
    }

    //gestion du temps
    if(deplacement) //si "deplacement" est vrai
    {
      timer = SDL_AddTimer(30, bougerZozor, &pZozor); //on initialise le timer avec la fonction "bougerZozor"
    }
    else //sinon
    {
      SDL_RemoveTimer(timer); //on arrête le timer
    }

    //on remet la surface de la fenêtre en blanc, pour effacer les traces des écrans précédent
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 255, 255, 255));

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

//fonction de déplacement de zozor
Uint32 bougerZozor(Uint32 intervalle, void *parametre)
{
  SDL_Rect* pZozor = parametre; //on convertit le pointeur void en pointeur SDL_Rect

  int versLaDroite = 1; //variable boléenne pour savoir dans quelle direction va zozor
  int versLeHaut = 0; //variable boléenne pour savoir dans quelle direction va zozor

  switch(pZozor->x) //on vérifie la position de zozor en abscisses
  {
    case 800 - 84: //si zozor a atteint le bout de la fenêtre sur la droite
      versLaDroite = 0; //alors on le déplacera vers la gauche
      versLeHaut = 1; //puis on le déplacera aussi vers le haut
      break;
    case 0: //si zozor est tout à gauche
      versLaDroite = 1; //alors on le déplacera vers la droite
      versLeHaut = 0; //alors on le déplacera aussi vers le bas
      break;
  }

  switch(pZozor->y) //puis en ordonnées
  {
    case 600 - 96: //si zozor atteint le bas de la fenêtre
      versLeHaut = 1; //alors on le fait remonter
      break;
    case 0: //s'il atteint le haut
      versLeHaut = 0; //alors on le fait redescendre
      break;
  }

  if(versLaDroite) //si zozor va vers la droite
  {
    pZozor->x++; //on va déplacer zozor de 1 pixel vers la droite
  }
  else // sinon
  {
    pZozor->x--; //on le déplace vers la gauche
  }

  if(versLeHaut) //si zozor va vers le haut
  {
    pZozor->y--;
  }
  else
  {
    pZozor->y++;
  }

  return intervalle;
}
