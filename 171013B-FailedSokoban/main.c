#include "main.h"
#include "fenetre.h"
#include "menuPrincipal.h"
#include "partie.h"
//#include "editeur.h"

int main()
{
  //on initie la bibliothèque et on crée la fenêtre
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *sokoban = fenetre();

  //on invoque une première fois le menu et on affecte la valeur qu'il renvoit à "choix"
  int choix = menuPrincipal(sokoban);

  //si "choix" n'est pas égal à 0, on lance le choix du joueur
  while(choix)
  {
    switch(choix)
    {
      case 1:
        partie(sokoban);
        break;
      case 2:
        //editeur();
        break;
    }

    choix = menuPrincipal(sokoban); //une fois la partie ou la création de niveau terminée, on relance le menu
  }

  fin(sokoban);

  return EXIT_SUCCESS;
}
