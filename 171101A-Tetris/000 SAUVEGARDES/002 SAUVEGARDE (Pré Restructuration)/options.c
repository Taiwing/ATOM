#include "main.h"
#include "images.h"
#include "options.h"
#include "son.h"

soundConfig *initialiserConfigSon()
{
  soundConfig *sound = malloc(sizeof(soundConfig)); //on crée la structure
  resetSoundConfig(sound); //en l'absence de fichier de configuration, on charge les valeurs par défaut
  return sound; //on renvoit la structure
}

void resetSoundConfig(soundConfig *sound)
{
  sound->soundOnOff[SOUND] = true; //le son général est activé
  sound->soundOnOff[THEME] = true; //le thème est activé
  sound->soundOnOff[FX] = true; //les FX sont activés

  sound->volume[0] = 1.0; //volume du thème
  sound->volume[1] = 1.0; //volume des FX
}

void destroySoundConfig(soundConfig *sound)
{
  free(sound);
}

gameConfig *initialiserConfigJeu()
{
  gameConfig *config = malloc(sizeof(gameConfig)); //on crée la structure
  resetGameConfig(config); //en l'absence de fichier de configuration, on charge les valeurs par défaut
  return config;
}

void resetGameConfig(gameConfig *config)
{
  //configuration sonore
  config->sound =initialiserConfigSon();

  //configuration de l'input du jeu
  config->keyMap[ROTATER][0] = ALLEGRO_KEY_UP;
  config->keyMap[ROTATER][1] = ALLEGRO_KEY_X;
  config->keyMap[ROTATER][2] = 0;
  config->keyMap[SOFTD][0] = ALLEGRO_KEY_DOWN;
  config->keyMap[SOFTD][1] = 0;
  config->keyMap[SOFTD][2] = 0;
  config->keyMap[LEFT][0] = ALLEGRO_KEY_LEFT;
  config->keyMap[LEFT][1] = 0;
  config->keyMap[LEFT][2] = 0;
  config->keyMap[RIGHT][0] = ALLEGRO_KEY_RIGHT;
  config->keyMap[RIGHT][1] = 0;
  config->keyMap[RIGHT][2] = 0;
  config->keyMap[HARDD][0] = ALLEGRO_KEY_SPACE;
  config->keyMap[HARDD][1] = 0;
  config->keyMap[HARDD][2] = 0;
  config->keyMap[ROTATEL][0] = ALLEGRO_KEY_RCTRL;
  config->keyMap[ROTATEL][1] = ALLEGRO_KEY_LCTRL;
  config->keyMap[ROTATEL][2] = ALLEGRO_KEY_W;
  config->keyMap[PAUSE][0] = ALLEGRO_KEY_P;
  config->keyMap[PAUSE][1] = ALLEGRO_KEY_F1;
  config->keyMap[PAUSE][2] = ALLEGRO_KEY_ESCAPE;
  config->keyMap[GHOST][0] = ALLEGRO_KEY_G;
  config->keyMap[GHOST][1] = 0;
  config->keyMap[GHOST][2] = 0;
  config->keyMap[CHANGE][0] = ALLEGRO_KEY_C;
  config->keyMap[CHANGE][1] = ALLEGRO_KEY_LSHIFT;
  config->keyMap[CHANGE][2] = ALLEGRO_KEY_RSHIFT;

  //autres paramètres
  config->cheatFunctions = false;
}

void destroyGameConfig(gameConfig *config)
{
  destroySoundConfig(config->sound);
  free(config);
}

void menuOptions(ALLEGRO_DISPLAY *fenetre, gameConfig *config, elementsFondOptions *elem, packOptions *images)
{
  al_install_mouse(); //on initialise la souris

  //variables de la boucle
  bool continuer = true; //valeur booléenne de la boucle principale
  bool redraw = false; //va déterminer quand on va redessiner l'image du menu
  int bouton = OFF; //va déterminer si la souris se trouve sur le bouton OK
  int vol[2]; //va recueillir et modifier la valeur des volumes
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
            //sauvegardeConfig(config); //on savegarde les changements dans le fichier de configuration
            continuer = false; //on quitte la boucle
            break;
          case VOLTHEMEM:
            if(config->sound->volume[0] > 0)
            {
              vol[0] -= 10;
              config->sound->volume[0] = tradInt(vol[0]);
            }
            break;
          case VOLTHEMEP:
            if(config->sound->volume[0] < 2)
            {
              vol[0] += 10;
              config->sound->volume[0] = tradInt(vol[0]);
            }
            break;
          case VOLFXM:
            if(config->sound->volume[1] > 0)
            {
              vol[1] -= 10;
              config->sound->volume[1] = tradInt(vol[1]);
            }
            break;
          case VOLFXP:
            if(config->sound->volume[1] < 2)
            {
              vol[1] += 10;
              config->sound->volume[1] = tradInt(vol[1]);
            }
            break;
          case RESET:
            break;
          /*default: //s'il est sur une zone d'input
            //inputOptions(bouton, config, elem, images);
            break;*/
        }
      }
    }

    if(redraw && al_is_event_queue_empty(event_queue_options)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherOptions(images, elem, bouton, vol); //on affiche le menu d'options à nouveau
      al_flip_display(); //on affiche les changements
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
  char volTheme[5], volFX[5];
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
    else if(floater == 0.2)
      return 10;
    else if(floater == 0.4)
      return 20;
    else if(floater == 0.6)
      return 30;
    else if(floater == 0.8)
      return 40;
    else if(floater == 1.0)
      return 50;
    else if(floater == 1.2)
      return 60;
    else if(floater == 1.4)
      return 70;
    else if(floater == 1.6)
      return 80;
    else if(floater == 1.8)
      return 90;
    else if(floater == 2.0)
      return 100;
}
