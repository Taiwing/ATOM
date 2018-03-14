#include<stdio.h>
#include<allegro5/allegro.h> //on inclut la bibliothèque allegro

int main()
{
  ALLEGRO_DISPLAY *display = NULL; //on crée un pointeur de type "display"

  if(!al_init()) //on initialise la bibliothèque, si ça ne marche pas
  {
    fprintf(stderr, "Erreur d'initialisation d'allegro !\n"); //on affiche un message d'erreur
    return -1;
  }

  display = al_create_display(640, 480); //on crée une fénêtre avec un écran de 640x480
  if(!display) //si la création de l'écran n'a pas marché
  {
    fprintf(stderr, "Erreur de création de l'écran !\n"); //on affiche un message d'erreur
    return -1;
  }

  al_clear_to_color(al_map_rgb(255, 0, 0)); //on rend l'écran rouge

  al_flip_display(); //on me à jour l'écran

  al_rest(10.0); //on met le preogramme en pause pour 10 secondes

  al_destroy_display(display); //on détruit l'écran

  return 0;
}
