#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "MNIST_helper.h"
#include "libft/libft.h"

const float FPS = 60;
const int SCREEN_W = 280;
const int SCREEN_H = 280;
enum MYKEYS {KEY_LEFT, KEY_RIGHT}; //on crée des constantes numériques pour les touches rentrées

int main(int argc, char *argv[])
{
  int test = 1;

  if(argc > 3 || (argc == 2  && ((!ft_str_is_numeric(argv[1]) || ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 9999) && ft_strcmp(argv[1], "-t"))))
  {
    printf("Error: wrong arguments\n");
    return -1;
  }
  else if(argc == 2 && !ft_strcmp(argv[1], "-t"))
  {
    show_MNIST_labels(NULL, !test);
    return 0;
  }
  else if(argc == 3  && ((!ft_str_is_numeric(argv[1]) || ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 9999) || ft_strcmp(argv[2], "-t")))
  {
    printf("Error: wrong arguments\n");
    return -1;
  }
  else if(argc == 3)
    test = 0;
  else if(argc == 1)
  {
    show_MNIST_labels(NULL, test);
    return 0;
  }

  ALLEGRO_DISPLAY *display = NULL; //on crée un pointeur vers un écran
  ALLEGRO_EVENT_QUEUE *event_queue = NULL; //on crée un pointeur vers la file d'évènements
  ALLEGRO_TIMER *timer = NULL; //on crée un pointeur vers un timer
  ALLEGRO_BITMAP *handy_number = NULL; //on crée un pointeur vers l'image qu'on va créer
  bool key[2] = {false, false}; //indique si une touche a été appuyée ou pas
  bool redraw = true; //on crée un booléen pour redessiner la fenêtre ou pas
  bool doexit = false;
  bool leginp = true;
  int index = atoi(argv[1]); //va servir à parcourir le fichier d'images

  al_init(); //on initie la bibliothèque
  al_install_keyboard(); //on intialise le clavier
  timer = al_create_timer(1.0 / FPS); //on initialise le timer à 1/60 secondes
  display = al_create_display(SCREEN_W, SCREEN_H); //on crée l'écran

  load_MNIST_bitmap(&handy_number, index, test); //on charge l'image qu'on veut afficher
  show_MNIST_labels(&index, test);
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
      if(key[KEY_LEFT] && index > 0)
      {
        index--;
        load_MNIST_bitmap(&handy_number, index, test); //on charge l'image qu'on veut afficher
        al_set_target_bitmap(al_get_backbuffer(display));
        show_MNIST_labels(&index, test);
        key[KEY_LEFT] = false; //on met la case du tableau de touche à faux
      }
      if(key[KEY_RIGHT] && index < 9999)
      {
        index++;
        load_MNIST_bitmap(&handy_number, index, test); //on charge l'image qu'on veut afficher
        al_set_target_bitmap(al_get_backbuffer(display));
        show_MNIST_labels(&index, test);
        key[KEY_RIGHT] = false; //on met la case du tableau de touche à faux
      }
      redraw = true; //on met notre booléen à true
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      break; //on quitte la boucle
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN && leginp) //s'il appuie sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_LEFT: //s'il appuie sur une flèche
          key[KEY_LEFT] = true; //on met la case du tableau de touche à vrai
          leginp = false;
          break;
        case ALLEGRO_KEY_RIGHT: //s'il appuie sur une flèche
          key[KEY_RIGHT] = true; //on met la case du tableau de touche à vrai
          leginp = false;
          break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_LEFT: //si c'est une flèche
          key[KEY_LEFT] = false; //on met la case du tableau de touche à faux
          leginp = true;
          break;
        case ALLEGRO_KEY_RIGHT: //si c'est une flèche
          key[KEY_RIGHT] = false; //on met la case du tableau de touche à faux
          leginp = true;
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
      al_draw_scaled_bitmap(handy_number, 0, 0, 28, 28, 0, 0, 280, 280, 0); //on dessine le handy_number
      al_flip_display(); //on met à jour l'écran
    }
  }

  al_destroy_bitmap(handy_number); //on détruit l'image
  al_destroy_timer(timer); //on détruit le timer
  al_destroy_display(display); //on détruit l'écran
  al_destroy_event_queue(event_queue); //on détruit la file d'évènements

  return 0;
}
