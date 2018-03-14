#include<stdio.h>
#include<allegro5/allegro.h>

int main()
{
  ALLEGRO_DISPLAY *display = NULL; //on crée un pointeur vers un écran
  ALLEGRO_EVENT_QUEUE *event_queue = NULL; //on crée un pointeur vers la file d'évènements

  al_init(); //on initie la bibliothèque
  display = al_create_display(640, 480); //on crée l'écran
  event_queue = al_create_event_queue(); //on crée la file d'évènements

  al_register_event_source(event_queue, al_get_display_event_source(display)); //on lie la file d'évènements à la fenêtre

  al_clear_to_color(al_map_rgb(255, 0, 0)); //on colore l'écran en rouge

  al_flip_display(); //on met à jour l'écran

  while(1) //tant que 1=1 lol (on fait une boucle infinie, qu'on arrête avec "break")
  {
    ALLEGRO_EVENT ev; //on crée une varible allegro de type event pour enregistrer l'évènement
    ALLEGRO_TIMEOUT timeout; //on crée un "timeout" pour définit le temps d'attente de la fonction "al_wait_for_event_until"
    al_init_timeout(&timeout, 0.06); //on initialise le timeout

    bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout); //ici on dit au programme d'attendre qu'un évènement se produise
    if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si un évènement se produit, et qu'il s'agit de la fermeture de la fenêtre
    {
      break; //on quitte la boucle
    }

    al_clear_to_color(al_map_rgb(255, 0, 0)); //on colore l'écran en rouge
    al_flip_display(); //on met à jour l'écran
  }

  al_destroy_display(display); //on détruit l'écran
  al_destroy_event_queue(event_queue); //on détruit la file d'évènements

  return 0;
}
