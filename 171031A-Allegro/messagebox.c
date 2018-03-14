#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"

int main()
{
  al_init(); //on initialise la bibliothèque

  //on affiche le message
  al_show_native_message_box(al_get_current_display(), "WESH", "saaaaaalut", "Je suis un message poto.", NULL, ALLEGRO_MESSAGEBOX_ERROR);

  return 0;
}
