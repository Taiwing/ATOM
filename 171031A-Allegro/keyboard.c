#include<stdio.h>
#include<allegro5/allegro.h>

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
enum MYKEYS {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT}; //on crée des constantes numériques pour les touches rentrées

int main()
{
  ALLEGRO_DISPLAY *display = NULL; //on crée un pointeur vers un écran
  ALLEGRO_EVENT_QUEUE *event_queue = NULL; //on crée un pointeur vers la file d'évènements
  ALLEGRO_TIMER *timer = NULL; //on crée un pointeur vers un timer
  ALLEGRO_BITMAP *bouncer = NULL; //on crée un pointeur vers l'image qu'on va créer
  float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0; //on centre l'image en x
  float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0; //puis en y
  float bouncer_dx = -4.0, bouncer_dy = 4.0; //on définit la vitesse du bouncer
  bool key[4] = {false, false, false, false}; //indique si une touche a été appuyée ou pas
  bool redraw = true; //on crée un booléen pour redessiner la fenêtre ou pas
  bool doexit = false;

  al_init(); //on initie la bibliothèque
  al_install_keyboard(); //on intialise le clavier
  timer = al_create_timer(1.0 / FPS); //on initialise le timer à 1/60 secondes
  display = al_create_display(SCREEN_W, SCREEN_H); //on crée l'écran

  bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE); //on crée l'image en rentrant la taille du "bouncer"
  al_set_target_bitmap(bouncer); //on cible le bouncer pour le remplissage
  al_clear_to_color(al_map_rgb(255, 0, 255)); //on colore le "bouncer"
  al_set_target_bitmap(al_get_backbuffer(display)); //on recible le backbuffer de la fenêtre (la surface sur laquelle on dessine par défaut)

  event_queue = al_create_event_queue(); //on crée la file d'évènements
  al_register_event_source(event_queue, al_get_display_event_source(display)); //on lie la file d'évènements à la fenêtre
  al_register_event_source(event_queue, al_get_timer_event_source(timer)); //on lie également la file au timer
  al_register_event_source(event_queue, al_get_keyboard_event_source()); //puis au clavier

  al_clear_to_color(al_map_rgb(0, 0, 0)); //on colore l'écran en noir

  al_flip_display(); //on met à jour l'écran

  al_start_timer(timer); //on démarre le timer

  while(!doexit) //tant que "doexit" est faux
  {
    ALLEGRO_EVENT ev; //on crée une varible allegro de type event pour enregistrer l'évènement
    al_wait_for_event(event_queue, &ev); //ici on dit au programme d'attendre qu'un évènement se produise (on a plus besoin de timeout)

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand on a un "tick" du timer, on raffiche la fenêtre
    {
      if(key[KEY_UP] && bouncer_y >= 4.0) //si le bouncer ne sort pas de la fenêtre
        bouncer_y -= 4.0; //on le déplace
      if(key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) //si le bouncer ne sort pas de la fenêtre
        bouncer_y += 4.0; //on le déplace
      if(key[KEY_LEFT] && bouncer_x >= 4.0) //si le bouncer ne sort pas de la fenêtre
        bouncer_x -= 4.0; //on le déplace
      if(key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0) //si le bouncer ne sort pas de la fenêtre
        bouncer_x += 4.0; //on le déplace
      redraw = true; //on met notre booléen à true
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      break; //on quitte la boucle
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_UP: //s'il appuie sur une flèche
          key[KEY_UP] = true; //on met la case du tableau de touche à vrai
          break;
        case ALLEGRO_KEY_DOWN: //s'il appuie sur une flèche
          key[KEY_DOWN] = true; //on met la case du tableau de touche à vrai
          break;
        case ALLEGRO_KEY_LEFT: //s'il appuie sur une flèche
          key[KEY_LEFT] = true; //on met la case du tableau de touche à vrai
          break;
        case ALLEGRO_KEY_RIGHT: //s'il appuie sur une flèche
          key[KEY_RIGHT] = true; //on met la case du tableau de touche à vrai
          break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_UP: //si c'est une flèche
          key[KEY_UP] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_DOWN: //si c'est une flèche
          key[KEY_DOWN] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_LEFT: //si c'est une flèche
          key[KEY_LEFT] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_RIGHT: //si c'est une flèche
          key[KEY_RIGHT] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_Q: //si c'est la touche 'q'
          doexit = true; //on sort de la boucle
          break;
      }
    }

    if(redraw && al_is_event_queue_empty(event_queue)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false; //on remet redraw à false
      al_clear_to_color(al_map_rgb(0, 0, 0)); //on remplit l'écran de noir
      al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0); //on dessine le bouncer
      al_flip_display(); //on met à jour l'écran
    }
  }

  al_destroy_bitmap(bouncer); //on détruit l'image
  al_destroy_timer(timer); //on détruit le timer
  al_destroy_display(display); //on détruit l'écran
  al_destroy_event_queue(event_queue); //on détruit la file d'évènements

  return 0;
}
