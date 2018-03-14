#include<stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"

int main()
{
  int continuer = 1, compteur = 1;
  char *c = malloc(sizeof(*c)); //caractère compteur pour la fenêtre
  *c = '1';
  char title[] = "fenetre 1";

  al_init(); //on initialise la bibliothèque

  while(continuer)
  {
    //on affiche le message et on switch la réponse
    switch(al_show_native_message_box(al_get_current_display(), title, "WESH", "Tu veux continuer ou pas ?", NULL, ALLEGRO_MESSAGEBOX_YES_NO))
    {
      case 0: //si le singe dit non, ou ferme la fenêtre
        continuer = 0;
        break;
      case 1: //s'il dit oui
        compteur++;
        sprintf(c, "%d", compteur);
        title[8] = *c;
        break;
      case 2: //WTF
        continuer = 0;
        break;
    }
  }
  return 0;
}
