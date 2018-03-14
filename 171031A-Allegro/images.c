#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

int main()
{
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_BITMAP *image = NULL;

  al_init(); //on charge la bibliothèque
  al_init_image_addon(); //on charge l'addon d'image
  display = al_create_display(800, 600); //on crée la fenêtre
  image = al_load_bitmap("devil.png"); //on charge l'image
  al_draw_bitmap(image, 200, 200, 0); //on dessine l'image dans la fenêtre
  al_flip_display(); //on met à jour la fenêtre
  al_rest(2); //on met en pause le programme pendant deux secondes

  al_destroy_display(display); //on détruit la fenêtre
  al_destroy_bitmap(image); //on détruit l'image bitmap

  return 0;
}
