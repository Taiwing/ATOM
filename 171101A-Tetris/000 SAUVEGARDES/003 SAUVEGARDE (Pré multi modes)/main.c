#include "main.h"
#include "fmain.h"

int main()
{
  //on initie la bibliothèque ALLEGRO
  al_init();

  al_init_image_addon(); //on charge l'addon d'image

  //puis on affiche le Menu Principal
  menuPrincipal();

  return EXIT_SUCCESS;
}
