#include "main.h"
#include "images.h"
#include "son.h"
#include "configuration.h"
#include "options.h"

void menuOptions(ALLEGRO_DISPLAY *fenetre, gameConfig *config, elementsFondOptions *elem, packOptions *images, packSons *sons)
{
  al_install_mouse(); //on initialise la souris

  //variables de la boucle
  bool continuer = true; //valeur booléenne de la boucle principale
  bool redraw = false; //va déterminer quand on va redessiner l'image du menu
  bool modifVolume = false; //va dire à la fonction son de modifier le volume de la musique
  int bouton = OFF; //va déterminer si la souris se trouve sur le bouton OK
  int vol[2] = {0, 0}; //va recueillir et modifier la valeur des volumes
  vol[0] = tradFloat(config->sound->volume[0]);
  vol[1] = tradFloat(config->sound->volume[1]);

  //on initialise le timer
  ALLEGRO_TIMER *timer_options = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_options = al_create_event_queue();
  al_register_event_source(event_queue_options, al_get_display_event_source(fenetre)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_options, al_get_timer_event_source(timer_options)); //on lie la file au timer
  al_register_event_source(event_queue_options, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_options, al_get_keyboard_event_source()); //puis au clavier

  //on démarre le timer
  al_start_timer(timer_options);

  while(continuer) //on lance la boucle du menu
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_options, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      redraw = true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      exit(EXIT_SUCCESS); //on quitte le programme
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) //si la souris bouge
    {
      //on vérifie si elle est ou non sur un bouton ou une zone d'input
      bouton = estSurUnBoutonOptions(elem, ev.mouse.x, ev.mouse.y);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) //si un bouton de la souris est relâché
    {
      //on vérifie si elle est ou non sur un bouton ou une zone d'input
      bouton = estSurUnBoutonOptions(elem, ev.mouse.x, ev.mouse.y);

      if(bouton != OFF && (ev.mouse.button & 1)) //si c'est le cas
      {
        switch(bouton)
        {
          case OK:
            enregistrerGameConfig(config); //on savegarde les changements dans le fichier de configuration
            continuer = false; //on quitte la boucle
            break;
          case VOLTHEMEM:
            if(config->sound->volume[0] > 0)
            {
              vol[0] -= 10;
              config->sound->volume[0] = tradInt(vol[0]);
              modifVolume = true;
            }
            break;
          case VOLTHEMEP:
            if(config->sound->volume[0] < 2)
            {
              vol[0] += 10;
              config->sound->volume[0] = tradInt(vol[0]);
              modifVolume = true;
            }
            break;
          case VOLFXM:
            if(config->sound->volume[1] > 0)
            {
              vol[1] -= 10;
              config->sound->volume[1] = tradInt(vol[1]);
              modifVolume = true;
            }
            break;
          case VOLFXP:
            if(config->sound->volume[1] < 2)
            {
              vol[1] += 10;
              config->sound->volume[1] = tradInt(vol[1]);
              modifVolume = true;
            }
            break;
          case RESET:
            resetGameConfig(config);
            //on régénère le pack options pour afficher les changements
            images = genererPackOptions(elem, al_get_backbuffer(fenetre), config->keyMap);
            al_set_target_bitmap(al_get_backbuffer(fenetre));
            break;
          default: //s'il est sur une zone d'input
            //on regénère l'image de fond de inputOptions
            images->fondInputOptions = genererFondInputOptions(elem, al_get_backbuffer(fenetre));
            al_set_target_bitmap(al_get_backbuffer(fenetre));
            al_uninstall_mouse();
            inputOptions(fenetre, bouton, config, elem, images);
            al_install_mouse();
            al_register_event_source(event_queue_options, al_get_mouse_event_source()); //puis on reprend les évènements de la souris en compte
            //on régénère le pack options pour afficher les changements
            images = genererPackOptions(elem, al_get_backbuffer(fenetre), config->keyMap);
            al_set_target_bitmap(al_get_backbuffer(fenetre));
            break;
        }
      }
    }

    if(redraw && al_is_event_queue_empty(event_queue_options)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherOptions(images, elem, bouton, vol); //on affiche le menu d'options à nouveau
      al_flip_display(); //on affiche les changements
      jouerSon(config->sound, sons, NULL, modifVolume);
      modifVolume = false;
    }
  }

  //on libère la mémoire
  al_destroy_timer(timer_options);
  al_destroy_event_queue(event_queue_options);
}

int estSurUnBoutonOptions(elementsFondOptions *elem, int x, int y)
{
  coord *rect = NULL;

  for(int i = 8; i < 23; i++)
  {
    switch(i)
    {
      case OK:
        rect = elem->rectOk;
        break;
      case IROTATER:
        rect = elem->rectIrotater;
        break;
      case ISOFTD:
        rect = elem->rectIsoftd;
        break;
      case ILEFT:
        rect = elem->rectIleft;
        break;
      case IRIGHT:
        rect = elem->rectIright;
        break;
      case IHARDD:
        rect = elem->rectIhardd;
        break;
      case IROTATEL:
        rect = elem->rectIrotatel;
        break;
      case IPAUSE:
        rect = elem->rectIpause;
        break;
      case IGHOST:
        rect = elem->rectIghost;
        break;
      case ICHANGE:
        rect = elem->rectIchange;
        break;
      case VOLTHEMEM:
        rect = elem->rectVolThemeM;
        break;
      case VOLTHEMEP:
        rect = elem->rectVolThemeP;
        break;
      case VOLFXM:
        rect = elem->rectVolFXM;
        break;
      case VOLFXP:
        rect = elem->rectVolFXP;
        break;
      case RESET:
        rect = elem->rectReset;
        break;
    }

    if(x >= rect->x && x <= rect->x2 && y >= rect->y && y <= rect->y2)
      return i;
  }

  //si elle n'est sur aucun des boutons ou des zones d'input
  return OFF;
}

void afficherOptions(packOptions *images, elementsFondOptions *elem, int bouton, int vol[2])
{
  //on charge l'image de fond
  al_draw_bitmap(images->fondOptions, 0, 0, 0);

  //on regarde sur quel bouton est la souris
  coord *rect = NULL;
  switch(bouton)
  {
    case OFF:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case OK:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case IROTATER:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case ISOFTD:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case ILEFT:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case IRIGHT:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case IHARDD:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case IROTATEL:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case IPAUSE:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case IGHOST:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case ICHANGE:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case VOLTHEMEM:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case VOLTHEMEP:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case VOLFXM:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case VOLFXP:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOn, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOff, rect->x + rect->t, rect->y + rect->t, 0);
      break;
    case RESET:
      rect = elem->rectOk;
      al_draw_bitmap(images->boutonOkOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotater;
      al_draw_bitmap(images->inputrotaterOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIsoftd;
      al_draw_bitmap(images->inputsoftdOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIleft;
      al_draw_bitmap(images->inputleftOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIright;
      al_draw_bitmap(images->inputrightOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIhardd;
      al_draw_bitmap(images->inputharddOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIrotatel;
      al_draw_bitmap(images->inputrotatelOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIpause;
      al_draw_bitmap(images->inputpauseOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIghost;
      al_draw_bitmap(images->inputghostOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectIchange;
      al_draw_bitmap(images->inputchangeOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeM;
      al_draw_bitmap(images->boutonVolThemeMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolThemeP;
      al_draw_bitmap(images->boutonVolThemePOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXM;
      al_draw_bitmap(images->boutonVolFXMOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectVolFXP;
      al_draw_bitmap(images->boutonVolFXPOff, rect->x + rect->t, rect->y + rect->t, 0);
      rect = elem->rectReset;
      al_draw_bitmap(images->boutonResetOn, rect->x + rect->t, rect->y + rect->t, 0);
      break;
  }

  //puis on affiche les valeurs du volume sonore
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);
  ALLEGRO_FONT *font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0);
  char volTheme[5] = "", volFX[5] = "";
  sprintf(volTheme, "%d%%", vol[0]);
  sprintf(volFX, "%d%%", vol[1]);
  rect = elem->rectVolThemeM;
  al_draw_text(font, bleuActif, (rect->x2 + 36), rect->y, ALLEGRO_ALIGN_CENTRE, volTheme);
  rect = elem->rectVolFXM;
  al_draw_text(font, bleuActif, (rect->x2 + 36), rect->y, ALLEGRO_ALIGN_CENTRE, volFX);
  al_destroy_font(font);
}

float tradInt(int integer)
{
  switch(integer)
  {
    case 0:
      return 0;
      break;
    case 10:
      return 0.2;
      break;
    case 20:
      return 0.4;
      break;
    case 30:
      return 0.6;
      break;
    case 40:
      return 0.8;
      break;
    case 50:
      return 1.0;
      break;
    case 60:
      return 1.2;
      break;
    case 70:
      return 1.4;
      break;
    case 80:
      return 1.6;
      break;
    case 90:
      return 1.8;
      break;
    case 100:
      return 2.0;
      break;
  }
}

int tradFloat(float floater)
{
    if(floater == 0)
      return 0;
    else if(floater < 0.21)
      return 10;
    else if(floater < 0.41)
      return 20;
    else if(floater < 0.61)
      return 30;
    else if(floater < 0.81)
      return 40;
    else if(floater < 1.01)
      return 50;
    else if(floater < 1.21)
      return 60;
    else if(floater < 1.41)
      return 70;
    else if(floater < 1.61)
      return 80;
    else if(floater < 1.81)
      return 90;
    else if(floater < 2.01)
      return 100;
}

void inputOptions(ALLEGRO_DISPLAY *fenetre, int bouton, gameConfig *config, elementsFondOptions *elem, packOptions *images)
{
  //variables de la boucle
  bool continuer = true; //valeur booléenne de la boucle principale
  bool redraw = false; //va déterminer quand on va redessiner l'image du menu
  int touche = 0; //va déterminer si la souris se trouve sur un bouton ou une zone d'input
  int zoneInput = 0; //va indiquer si le singe a cliqué sur une zone d'input et donc qu'un
  bool key[ALLEGRO_KEY_MAX] = {false}; //va déterminer quelle touche a été pressée
  int input[3] = {0}; //va récupérer la valeur de l'input et l'envoyer à la fonction d'affichage
  bool legalInput = true; //va servir à limiter l'input des touches

  //on initialise le timer
  ALLEGRO_TIMER *timer_inputOptions = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  al_install_mouse(); //on installe la souris

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_inputOptions = al_create_event_queue();
  al_register_event_source(event_queue_inputOptions, al_get_display_event_source(fenetre)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_inputOptions, al_get_timer_event_source(timer_inputOptions)); //on lie la file au timer
  al_register_event_source(event_queue_inputOptions, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_inputOptions, al_get_keyboard_event_source()); //puis au clavier

  //on démarre le timer
  al_start_timer(timer_inputOptions);

  while(continuer) //on lance la boucle du menu
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_inputOptions, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      //gestion des input
      for(int i = 0; i < ALLEGRO_KEY_MAX; i++) //on parcourt le tableau des touches
      {
        if(key[i]) //si une touche a été appuyée
        {
          switch(zoneInput)
          {
            case TOUCHE1:
              input[0] = i;
              key[i] = false;
              zoneInput = 0;
              break;
            case TOUCHE2:
              input[1] = i;
              key[i] = false;
              zoneInput = 0;
              break;
            case TOUCHE3:
              input[2] = i;
              key[i] = false;
              zoneInput = 0;
              break;
            default:
              key[i] = false;
              zoneInput = 0;
              break;
          }
        }
      }
      redraw = true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      exit(EXIT_SUCCESS); //on quitte le programme
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) //si la souris bouge
    {
      //on vérifie où se trouve la souris
      touche = estSurUnBoutonInputOptions(elem, ev.mouse.x, ev.mouse.y);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) //si un bouton de la souris est relâché
    {
      //on vérifie où se trouve la souris
      touche = estSurUnBoutonInputOptions(elem, ev.mouse.x, ev.mouse.y);

      if(touche != 0 && (ev.mouse.button & 1)) //si c'est un clic gauche sur l'un des touches
      {
        switch(touche)
        {
          case OKINPOPT:
            //on enregistre les modifications de la configuration
            for(int i = 0; i < 3; i++)
            {
              if(input[i] != 0)
                config->keyMap[bouton - 9][i] = input[i];
            }
            continuer = false; //on sort de la boucle
            break;
          default:
            zoneInput = touche;
            break;
        }
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      if(legalInput)
      {
        key[ev.keyboard.keycode] = true; //on met la case du tableau de touche à vrai
        legalInput = false;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      legalInput = true;
    }

    if(redraw && al_is_event_queue_empty(event_queue_inputOptions)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherInputOptions(images, elem, bouton, touche, zoneInput, config, input); //on affiche l'image de inputOptions à nouveau
      al_flip_display(); //on affiche les changements
    }
  }

  //on libère la mémoire
  al_destroy_timer(timer_inputOptions);
  al_destroy_event_queue(event_queue_inputOptions);
}

void afficherInputOptions(packOptions *images, elementsFondOptions *elem, int bouton, int touche, int zoneInput, gameConfig *config, int input[3])
{
  //d'abord on affiche le fond (avec le cadre généré à la volée avant l'appel de la fonction inputOptions)
  al_draw_bitmap(images->fondInputOptions, 0, 0, 0);

  ALLEGRO_FONT *font = al_load_ttf_font("Raleway-Bold.ttf", 20, 0);
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);
  coord *rect = elem->rectInputOptions;

  //puis on affiche le titre du cadre
  switch(bouton)
  {
    case IROTATER:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "ROTATION DROITE");
      break;
    case ISOFTD:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "SOFT DROP");
      break;
    case ILEFT:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "MOUVEMENT GAUCHE");
      break;
    case IRIGHT:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "MOUVEMENT DROITE");
      break;
    case IHARDD:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "HARD DROP");
      break;
    case IROTATEL:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "ROTATION GAUCHE");
      break;
    case IPAUSE:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "PAUSE");
      break;
    case IGHOST:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "PIECE FANTOME");
      break;
    case ICHANGE:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 5, ALLEGRO_ALIGN_CENTRE, "PIECE SUIVANTE");
      break;
  }

  //puis on gère la position de la souris par rapport aux trois zones d'input et au bouton OK
  switch(touche)
  {
    case 0:
      al_draw_bitmap(images->boutonOkInpOptOff, elem->rectOkInpOpt->x + elem->rectOkInpOpt->t, elem->rectOkInpOpt->y + elem->rectOkInpOpt->t, 0);
      al_draw_bitmap(images->touche1Off, elem->rectTouche1->x + elem->rectTouche1->t, elem->rectTouche1->y + elem->rectTouche1->t, 0);
      al_draw_bitmap(images->touche2Off, elem->rectTouche2->x + elem->rectTouche2->t, elem->rectTouche2->y + elem->rectTouche2->t, 0);
      al_draw_bitmap(images->touche3Off, elem->rectTouche3->x + elem->rectTouche3->t, elem->rectTouche3->y + elem->rectTouche3->t, 0);
      break;
    case OKINPOPT:
      al_draw_bitmap(images->boutonOkInpOptOn, elem->rectOkInpOpt->x + elem->rectOkInpOpt->t, elem->rectOkInpOpt->y + elem->rectOkInpOpt->t, 0);
      al_draw_bitmap(images->touche1Off, elem->rectTouche1->x + elem->rectTouche1->t, elem->rectTouche1->y + elem->rectTouche1->t, 0);
      al_draw_bitmap(images->touche2Off, elem->rectTouche2->x + elem->rectTouche2->t, elem->rectTouche2->y + elem->rectTouche2->t, 0);
      al_draw_bitmap(images->touche3Off, elem->rectTouche3->x + elem->rectTouche3->t, elem->rectTouche3->y + elem->rectTouche3->t, 0);
      break;
    case TOUCHE1:
      al_draw_bitmap(images->boutonOkInpOptOff, elem->rectOkInpOpt->x + elem->rectOkInpOpt->t, elem->rectOkInpOpt->y + elem->rectOkInpOpt->t, 0);
      al_draw_bitmap(images->touche1On, elem->rectTouche1->x + elem->rectTouche1->t, elem->rectTouche1->y + elem->rectTouche1->t, 0);
      al_draw_bitmap(images->touche2Off, elem->rectTouche2->x + elem->rectTouche2->t, elem->rectTouche2->y + elem->rectTouche2->t, 0);
      al_draw_bitmap(images->touche3Off, elem->rectTouche3->x + elem->rectTouche3->t, elem->rectTouche3->y + elem->rectTouche3->t, 0);
      break;
    case TOUCHE2:
      al_draw_bitmap(images->boutonOkInpOptOff, elem->rectOkInpOpt->x + elem->rectOkInpOpt->t, elem->rectOkInpOpt->y + elem->rectOkInpOpt->t, 0);
      al_draw_bitmap(images->touche1Off, elem->rectTouche1->x + elem->rectTouche1->t, elem->rectTouche1->y + elem->rectTouche1->t, 0);
      al_draw_bitmap(images->touche2On, elem->rectTouche2->x + elem->rectTouche2->t, elem->rectTouche2->y + elem->rectTouche2->t, 0);
      al_draw_bitmap(images->touche3Off, elem->rectTouche3->x + elem->rectTouche3->t, elem->rectTouche3->y + elem->rectTouche3->t, 0);
      break;
    case TOUCHE3:
      al_draw_bitmap(images->boutonOkInpOptOff, elem->rectOkInpOpt->x + elem->rectOkInpOpt->t, elem->rectOkInpOpt->y + elem->rectOkInpOpt->t, 0);
      al_draw_bitmap(images->touche1Off, elem->rectTouche1->x + elem->rectTouche1->t, elem->rectTouche1->y + elem->rectTouche1->t, 0);
      al_draw_bitmap(images->touche2Off, elem->rectTouche2->x + elem->rectTouche2->t, elem->rectTouche2->y + elem->rectTouche2->t, 0);
      al_draw_bitmap(images->touche3On, elem->rectTouche3->x + elem->rectTouche3->t, elem->rectTouche3->y + elem->rectTouche3->t, 0);
      break;
  }

  //si zoneInput n'est pas égal à 0 (si le singe a cliqué sur l'une des zones pour y rentrer une touche)
  if(zoneInput)
  {
    switch(zoneInput)
    {
      case TOUCHE1:
        if(touche != TOUCHE1)
          al_draw_bitmap(images->touche1On, elem->rectTouche1->x + elem->rectTouche1->t, elem->rectTouche1->y + elem->rectTouche1->t, 0);
        break;
      case TOUCHE2:
        if(touche != TOUCHE2)
          al_draw_bitmap(images->touche2On, elem->rectTouche2->x + elem->rectTouche2->t, elem->rectTouche2->y + elem->rectTouche2->t, 0);
        break;
      case TOUCHE3:
        if(touche != TOUCHE3)
          al_draw_bitmap(images->touche3On, elem->rectTouche3->x + elem->rectTouche3->t, elem->rectTouche3->y + elem->rectTouche3->t, 0);
        break;
    }
  }

  //puis on affiche la touche correspondante dans chaque zone (celle par défaut s'il n'y a pas encore eu d'input)
  //on arrête d'afficher la touche qu'il y avait et on laisse la zone sélectionnée (comme si la souris était dessus)
  ALLEGRO_FONT *font2 = al_load_ttf_font("Raleway-Bold.ttf", 15, 0);
  char strTouche1[30], strTouche2[30], strTouche3[30]; //va contenir le nom de la touche choisie
  for(int i = 0; i < 3; i++)
  {
    if(zoneInput != (i + 1))
    {
      switch(i)
      {
        case 0:
          if(input[i] != 0)
            strToucheZoneInput(input[i], strTouche1); //on traduit la touche choisie par le joueur en string
          else
            strToucheZoneInput(config->keyMap[bouton - 9][i], strTouche1); //on traduit la touche en string
          rect = elem->rectTouche1;
          if(strTouche1[0] != '\0')
            al_draw_text(font2, bleuActif, rect->x + ((rect->x2 - rect->x) /2), rect->y, ALLEGRO_ALIGN_CENTRE, strTouche1);
          break;
        case 1:
          if(input[i] != 0)
            strToucheZoneInput(input[i], strTouche2); //on traduit la touche choisie par le joueur en string
          else
            strToucheZoneInput(config->keyMap[bouton - 9][i], strTouche2); //on traduit la touche en string
          rect = elem->rectTouche2;
          if(strTouche2[0] != '\0')
            al_draw_text(font2, bleuActif, rect->x + ((rect->x2 - rect->x) /2), rect->y, ALLEGRO_ALIGN_CENTRE, strTouche2);
          break;
        case 2:
          if(input[i] != 0)
            strToucheZoneInput(input[i], strTouche3); //on traduit la touche choisie par le joueur en string
          else
            strToucheZoneInput(config->keyMap[bouton - 9][i], strTouche3); //on traduit la touche en string
          rect = elem->rectTouche3;
          if(strTouche3[0] != '\0')
            al_draw_text(font2, bleuActif, rect->x + ((rect->x2 - rect->x) /2), rect->y, ALLEGRO_ALIGN_CENTRE, strTouche3);
          break;
      }
    }
  }

  al_destroy_font(font);
  al_destroy_font(font2);
}

void strToucheZoneInput(int touche, char str[30])
{
  //on écrit la chaîne de caractère
  switch(touche) //on détermine laquelle
  {
    case ALLEGRO_KEY_A:
      str[0] = 'A';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_Z:
      str[0] = 'Z';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_E:
      str[0] = 'E';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_R:
      str[0] = 'R';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_T:
      str[0] = 'T';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_Y:
      str[0] = 'Y';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_U:
      str[0] = 'U';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_I:
      str[0] = 'I';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_O:
      str[0] = 'O';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_P:
      str[0] = 'P';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_Q:
      str[0] = 'Q';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_S:
      str[0] = 'S';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_D:
      str[0] = 'D';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_F:
      str[0] = 'F';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_G:
      str[0] = 'G';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_H:
      str[0] = 'H';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_J:
      str[0] = 'J';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_K:
      str[0] = 'K';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_L:
      str[0] = 'L';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_M:
      str[0] = 'M';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_W:
      str[0] = 'W';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_X:
      str[0] = 'X';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_C:
      str[0] = 'C';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_V:
      str[0] = 'V';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_B:
      str[0] = 'B';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_N:
      str[0] = 'N';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_0:
      str[0] = '0';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_1:
      str[0] = '1';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_2:
      str[0] = '2';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_3:
      str[0] = '3';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_4:
      str[0] = '4';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_5:
      str[0] = '5';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_6:
      str[0] = '6';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_7:
      str[0] = '7';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_8:
      str[0] = '8';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_9:
      str[0] = '9';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_TILDE:
      sprintf(str, ")");
      break;
    case ALLEGRO_KEY_EQUALS:
      sprintf(str, "EQUALS");
      break;
    case ALLEGRO_KEY_MINUS:
      str[0] = '^';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_OPENBRACE:
      str[0] = '$';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_CLOSEBRACE:
      str[0] = 'u';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_BACKSLASH:
      str[0] = '*';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_COMMA:
      str[0] = ',';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_SEMICOLON:
      str[0] = ';';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_FULLSTOP:
      str[0] = ':';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_SLASH:
      str[0] = '!';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_QUOTE:
      str[0] = 'e';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_BACKSLASH2:
      str[0] = '<';
      str[1] = '\0';
      break;
    case ALLEGRO_KEY_LSHIFT:
      sprintf(str, "LSHIFT");
      break;
    case ALLEGRO_KEY_RSHIFT:
      sprintf(str, "RSHIFT");
      break;
    case ALLEGRO_KEY_LCTRL:
      sprintf(str, "LCTRL");
      break;
    case ALLEGRO_KEY_RCTRL:
      sprintf(str, "RCTRL");
      break;
    case ALLEGRO_KEY_ALT:
      sprintf(str, "ALT");
      break;
    case ALLEGRO_KEY_ALTGR:
      sprintf(str, "ALTGR");
      break;
    case ALLEGRO_KEY_TAB:
      sprintf(str, "TAB");
      break;
    case ALLEGRO_KEY_BACKSPACE:
      sprintf(str, "BACKSPACE");
      break;
    case ALLEGRO_KEY_SPACE:
      sprintf(str, "SPACE");
      break;
    case ALLEGRO_KEY_UP:
      sprintf(str, "HAUT");
      break;
    case ALLEGRO_KEY_DOWN:
      sprintf(str, "BAS");
      break;
    case ALLEGRO_KEY_LEFT:
      sprintf(str, "GAUCHE");
      break;
    case ALLEGRO_KEY_RIGHT:
      sprintf(str, "DROITE");
      break;
    case ALLEGRO_KEY_F1:
      sprintf(str, "F1");
      break;
    case ALLEGRO_KEY_F2:
      sprintf(str, "F2");
      break;
    case ALLEGRO_KEY_F3:
      sprintf(str, "F3");
      break;
    case ALLEGRO_KEY_F4:
      sprintf(str, "F4");
      break;
    case ALLEGRO_KEY_F5:
      sprintf(str, "F5");
      break;
    case ALLEGRO_KEY_F6:
      sprintf(str, "F6");
      break;
    case ALLEGRO_KEY_F7:
      sprintf(str, "F7");
      break;
    case ALLEGRO_KEY_F8:
      sprintf(str, "F8");
      break;
    case ALLEGRO_KEY_F9:
      sprintf(str, "F9");
      break;
    case ALLEGRO_KEY_F10:
      sprintf(str, "F10");
      break;
    case ALLEGRO_KEY_F11:
      sprintf(str, "F11");
      break;
    case ALLEGRO_KEY_F12:
      sprintf(str, "F12");
      break;
    case ALLEGRO_KEY_ESCAPE:
      sprintf(str, "ESCAPE");
      break;
    case ALLEGRO_KEY_ENTER:
      sprintf(str, "ENTER");
      break;
    default:
      str[0] = '\0';
      break;
  }
}

int estSurUnBoutonInputOptions(elementsFondOptions *elem, int x, int y)
{
  coord *rect = NULL;

  for(int i = 1; i < 5; i++)
  {
    switch(i)
    {
      case TOUCHE1:
        rect = elem->rectTouche1;
        break;
      case TOUCHE2:
        rect = elem->rectTouche2;
        break;
      case TOUCHE3:
        rect = elem->rectTouche3;
        break;
      case OKINPOPT:
        rect = elem->rectOkInpOpt;
        break;
    }

    if(x >= rect->x && x <= rect->x2 && y >= rect->y && y <= rect->y2)
      return i;
  }

  //si elle n'est sur aucun des boutons ou des zones d'input
  return 0;
}
