#include<stdio.h>
#include<allegro5/allegro.h>

const float FPS = 60;

int main()
{
  ALLEGRO_DISPLAY *display = NULL; //on crée un pointeur vers un écran
  ALLEGRO_EVENT_QUEUE *event_queue = NULL; //on crée un pointeur vers la file d'évènements
  ALLEGRO_TIMER *timer = NULL; //on crée un pointeur vers un timer
  bool redraw = true; //on crée un booléen pour redessiner la fenêtre ou pas

  al_init(); //on initie la bibliothèque
  timer = al_create_timer(1.0 / FPS); //on initialise le timer à 1/60 secondes
  display = al_create_display(640, 480); //on crée l'écran
  event_queue = al_create_event_queue(); //on crée la file d'évènements
  al_register_event_source(event_queue, al_get_display_event_source(display)); //on lie la file d'évènements à la fenêtre
  al_register_event_source(event_queue, al_get_timer_event_source(timer)); //on également la file au timer

  al_clear_to_color(al_map_rgb(255, 0, 0)); //on colore l'écran en rouge

  al_flip_display(); //on met à jour l'écran

  al_start_timer(timer); //on démarre le timer

  while(1) //tant que 1=1 lol (on fait une boucle infinie, qu'on arrête avec "break")
  {
    ALLEGRO_EVENT ev; //on crée une varible allegro de type event pour enregistrer l'évènement

    al_wait_for_event(event_queue, &ev); //ici on dit au programme d'attendre qu'un évènement se produise (on a plus besoin de timeout)
    if(ev.type == ALLEGRO_EVENT_TIMER) //quand on a un "tick" du timer, on raffiche la fenêtre
    {
      redraw = true; //on met notre booléen à true
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si un évènement se produit, et qu'il s'agit de la fermeture de la fenêtre
    {
      break; //on quitte la boucle
    }

    if(redraw && al_is_event_queue_empty(event_queue)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false; //on remet redraw à false
      al_clear_to_color(al_map_rgb(255, 0, 0)); //on colore l'écran en rouge
      al_flip_display(); //on met à jour l'écran
    }
  }

  al_destroy_display(display); //on détruit l'écran
  al_destroy_event_queue(event_queue); //on détruit la file d'évènements

  return 0;
}
