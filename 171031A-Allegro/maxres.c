#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"

int main()
{
  ALLEGRO_DISPLAY *display = NULL; //pointeur vers l'écran
  ALLEGRO_DISPLAY_MODE disp_data; //permet de stocker des infos sur l'écran de l'ordinateur

  al_init(); //on initie la bibliothèque
  al_init_image_addon();
  al_init_primitives_addon();

  al_get_display_mode(0, &disp_data); //on récupère les données de l'écran pour la résolution maximum

  al_set_new_display_flags(ALLEGRO_FULLSCREEN);
  display = al_create_display(disp_data.width, disp_data.height);

  al_clear_to_color(al_map_rgb(255, 0, 0)); //on remplit l'écran de rouge
  al_flip_display(); //on met à jour l'écran

  al_rest(3); //on fait une pause de 3 secondes
  al_destroy_display(display); //on détruit l'écran

  return 0;
}
