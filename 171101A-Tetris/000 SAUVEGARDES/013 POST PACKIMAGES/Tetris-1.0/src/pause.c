#include "include/pause.h"

bool menuPause(gameScreen *screen, elements *elem, packImages *images, int niveau, int score, int lignes, packSons *sons, gameConfig *config)
{
  //on charge la liste d'éléments pour la fonction "estSurUnBouton"
  Liste *lElem = initialisationListe();
  chargerListeElemFondPause(screen, elem, lElem);

  //variables de la boucle
  bool quit = false; //valeur booléenne qu'on va renvoyer (va quitter la partie si vraie)
  bool continuer = true; //valeur booléenne de la boucle principale
  bool redraw = false; //va déterminer quand on va redessiner l'image du menu
  bool legalInput = true;
  int bouton = OFF; //va déterminer sur quel bouton du menu se trouve la souris

  //on initialise le timer
  ALLEGRO_TIMER *timer_pause = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_pause = al_create_event_queue();
  al_register_event_source(event_queue_pause, al_get_display_event_source(screen->display)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_pause, al_get_timer_event_source(timer_pause)); //on lie la file au timer
  al_register_event_source(event_queue_pause, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_pause, al_get_keyboard_event_source()); //et au clavier

  //on démarre le timer
  al_start_timer(timer_pause);

  while(continuer) //on lance la boucle du menu
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_pause, &ev); //on attend qu'un évènement se produise

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
      //on vérifie si elle est ou non sur un bouton
      bouton = estSurUnBoutonPause(lElem, ev.mouse.x, ev.mouse.y);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) //si un bouton de la souris est relâché
    {
      //on vérifie si elle est ou non sur un bouton
      bouton = estSurUnBoutonPause(lElem, ev.mouse.x, ev.mouse.y);

      if(bouton != OFF) //si c'est le cas
      {
        switch(bouton)
        {
          case REPRENDRE:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              continuer = false; //on arrête la boucle et on reprend la partie
            }
            break;
          case AIDE:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              //on affiche un panneau d'aide avec toutes les touches et leurs fonctions
              al_unregister_event_source(event_queue_pause, al_get_keyboard_event_source());
              al_uninstall_mouse();
              menuAide(screen, images->imagesPartie->imagesPause->fondMenuAide, images->imagesPartie->imagesPause->boutonOkOn, images->imagesPartie->imagesPause->boutonOkOff, elem->rectAide, elem->rectBAideOk, elem->rectNSL, niveau, score, lignes);
              al_install_mouse();
              al_register_event_source(event_queue_pause, al_get_mouse_event_source()); //puis on reprend les évènements de la souris en compte
              al_register_event_source(event_queue_pause, al_get_keyboard_event_source()); //et au clavier
            }
            break;
          case OPTIONS:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              al_unregister_event_source(event_queue_pause, al_get_keyboard_event_source());
              al_uninstall_mouse();
              menuOptions(screen, config, elem, images, sons);
              al_install_mouse();
              al_register_event_source(event_queue_pause, al_get_keyboard_event_source()); //et au clavier
              al_register_event_source(event_queue_pause, al_get_mouse_event_source()); //puis on reprend les évènements de la souris en compte
            }
            break;
          case QUITTER:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              continuer = false; //on arrête la boucle
              quit = true; //et on quitte la partie
            }
            break;
        }
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      windowInputKeyDown(screen, ev.keyboard.keycode, &legalInput);
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      windowInputKeyUp(screen, ev.keyboard.keycode, &legalInput);
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE || screen->fullScreenSwitch)
    {
      if(screen->fullScreenSwitch)
      {
        fullScreen(screen);
        screen->fullScreenSwitch = false;
      }
      resizeGameScreen(screen);
      dechargerListe(lElem);
      chargerListeElemFondPause(screen, elem, lElem);
    }

    if(redraw && al_is_event_queue_empty(event_queue_pause)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherPause(screen, images->imagesPartie->imagesPause, elem, bouton, niveau, score, lignes); //on affiche la pause à nouveau
    }
  }

  //on libère la mémoire
  detruireListe(lElem);
  al_destroy_timer(timer_pause);
  al_destroy_event_queue(event_queue_pause);

  return quit;
}

int estSurUnBoutonPause(Liste *lElem, int x, int y)
{
  switch(posMouse(lElem, x, y))
  {
    case 1:
      return REPRENDRE;
      break;
    case 2:
      return AIDE;
      break;
    case 3:
      return OPTIONS;
      break;
    case 4:
      return QUITTER;
      break;
    default:
      return OFF;
      break;
  }
}

void afficherPause(gameScreen *screen, packPause *images, elements* elem, int bouton, int niveau, int score, int lignes)
{
  //on cible le buffer du jeu sur lequel on va dessiner
  al_set_target_bitmap(screen->buffer);
  al_clear_to_color(al_map_rgb(0, 0, 0));

  //on charge l'image de fond
  al_draw_bitmap(images->fondPause, 0, 0, 0);

  //on charge le pointeur "coord" pour raccourcir les lignes suivantes
  coord *rect = elem->rectNSL;

  //on traduit les valeurs de "niveau", "score" et lignes en chaîne de caractère
  char strNiveau[3]; //trois caractère max (de 1 à 99)
  char strScore[7]; //six caractères max (de 1 999999)
  char strLignes[6]; //cinq caractères max (de 1 99999)
  sprintf(strNiveau, "%d", niveau);
  sprintf(strScore, "%d", score);
  sprintf(strLignes, "%d", lignes);

  //maintenant on va écrire dans les cases du septième rectangle qu'on a créé
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  //affiche la valeur de "niveau" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + rect->t + 9, ALLEGRO_ALIGN_RIGHT, strNiveau);
  //affiche la valeur de "score" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + (rect->t * 2) + 48 + 9, ALLEGRO_ALIGN_RIGHT, strScore);
  //affiche la valeur de "lignes" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y2 - rect->t - 48 + 9, ALLEGRO_ALIGN_RIGHT, strLignes);

  //puis les boutons
  switch(bouton)
  {
    case OFF:
      al_draw_bitmap(images->boutonReprendreOff, elem->rectBPauseReprendre->x + elem->rectBPauseReprendre->t, elem->rectBPauseReprendre->y + elem->rectBPauseReprendre->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectBPauseAide->x + elem->rectBPauseAide->t, elem->rectBPauseAide->y + elem->rectBPauseAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectBPauseOptions->x + elem->rectBPauseOptions->t, elem->rectBPauseOptions->y + elem->rectBPauseOptions->t, 0);
      al_draw_bitmap(images->boutonQuitterOff, elem->rectBPauseQuitter->x + elem->rectBPauseQuitter->t, elem->rectBPauseQuitter->y + elem->rectBPauseQuitter->t, 0);
      break;
    case REPRENDRE:
      al_draw_bitmap(images->boutonReprendreOn, elem->rectBPauseReprendre->x + elem->rectBPauseReprendre->t, elem->rectBPauseReprendre->y + elem->rectBPauseReprendre->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectBPauseAide->x + elem->rectBPauseAide->t, elem->rectBPauseAide->y + elem->rectBPauseAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectBPauseOptions->x + elem->rectBPauseOptions->t, elem->rectBPauseOptions->y + elem->rectBPauseOptions->t, 0);
      al_draw_bitmap(images->boutonQuitterOff, elem->rectBPauseQuitter->x + elem->rectBPauseQuitter->t, elem->rectBPauseQuitter->y + elem->rectBPauseQuitter->t, 0);
      break;
    case AIDE:
      al_draw_bitmap(images->boutonReprendreOff, elem->rectBPauseReprendre->x + elem->rectBPauseReprendre->t, elem->rectBPauseReprendre->y + elem->rectBPauseReprendre->t, 0);
      al_draw_bitmap(images->boutonAideOn, elem->rectBPauseAide->x + elem->rectBPauseAide->t, elem->rectBPauseAide->y + elem->rectBPauseAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectBPauseOptions->x + elem->rectBPauseOptions->t, elem->rectBPauseOptions->y + elem->rectBPauseOptions->t, 0);
      al_draw_bitmap(images->boutonQuitterOff, elem->rectBPauseQuitter->x + elem->rectBPauseQuitter->t, elem->rectBPauseQuitter->y + elem->rectBPauseQuitter->t, 0);
      break;
    case OPTIONS:
      al_draw_bitmap(images->boutonReprendreOff, elem->rectBPauseReprendre->x + elem->rectBPauseReprendre->t, elem->rectBPauseReprendre->y + elem->rectBPauseReprendre->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectBPauseAide->x + elem->rectBPauseAide->t, elem->rectBPauseAide->y + elem->rectBPauseAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOn, elem->rectBPauseOptions->x + elem->rectBPauseOptions->t, elem->rectBPauseOptions->y + elem->rectBPauseOptions->t, 0);
      al_draw_bitmap(images->boutonQuitterOff, elem->rectBPauseQuitter->x + elem->rectBPauseQuitter->t, elem->rectBPauseQuitter->y + elem->rectBPauseQuitter->t, 0);
      break;
    case QUITTER:
      al_draw_bitmap(images->boutonReprendreOff, elem->rectBPauseReprendre->x + elem->rectBPauseReprendre->t, elem->rectBPauseReprendre->y + elem->rectBPauseReprendre->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectBPauseAide->x + elem->rectBPauseAide->t, elem->rectBPauseAide->y + elem->rectBPauseAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectBPauseOptions->x + elem->rectBPauseOptions->t, elem->rectBPauseOptions->y + elem->rectBPauseOptions->t, 0);
      al_draw_bitmap(images->boutonQuitterOn, elem->rectBPauseQuitter->x + elem->rectBPauseQuitter->t, elem->rectBPauseQuitter->y + elem->rectBPauseQuitter->t, 0);
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  drawBuffer(screen);
}

void chargerListeElemFondPause(gameScreen *screen, elements *elem, Liste *lElem)
{
  coord *rect = NULL;
  for(int i = 0; i < 4; i++)
  {
    switch(i)
    {
      case 0:
        rect = elem->rectBPauseReprendre;
        break;
      case 1:
        rect = elem->rectBPauseAide;
        break;
      case 2:
        rect = elem->rectBPauseOptions;
        break;
      case 3:
        rect = elem->rectBPauseQuitter;
        break;
    }

    elemToList(screen, lElem, rect);
  }
}
