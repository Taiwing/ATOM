#include<stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

int main()
{
  al_init(); //on initie la bibliothèque
  al_init_font_addon(); //on initie l'addon de police de caractères
  al_init_ttf_addon(); //on initie l'addon "ttf"

  ALLEGRO_DISPLAY *display = al_create_display(640, 480); //on crée un fenêtre de 640x480
  ALLEGRO_FONT *font = al_load_ttf_font("pirulen.ttf", 30, 0); //on charge la police "pirulen"

  al_clear_to_color(al_map_rgb(50, 10, 70)); //on colore le fond de la fenêtre
  al_draw_text(font, al_map_rgb(255, 255, 255), 640/2, (480/2) - 30, ALLEGRO_ALIGN_CENTRE, "WESH, bien ou bien ?"); //on écrit en blanc au milieu

  al_flip_display(); //on met à jour la fenêtre
  al_rest(10.0); //on met en pause dix secondes
  al_destroy_display(display); //on libère la mémoire

  return 0;
}
